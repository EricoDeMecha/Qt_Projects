#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // make  the portal button disappear
    ui->btn_portal->setVisible(false);
    ui->btn_reportCrime->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);// set it to home page
    // plots at the dashboard
    plotCustomPlot0();
    plotCustomPlot1();
    plotCustomPlot2();
    plotCustomPlot3();
    plotCustomPlot4();
    // connect the register button
    connect(ui->btn_login, &QPushButton::clicked,this, [this](){
        Login lg;
        lg.setWindowTitle("Login");
        lg.setModal(true);
        lg.exec();
        if(lg._uExit){
           ui->btn_register->setVisible(false);
           ui->btn_login->setVisible(false);
           ui->stackedWidget->setCurrentIndex(0);

           ui->lbl_usr->setText(lg.username);
           ui->lbl_usr1->setText(lg.username);
           if(lg.access_level > 1){
               ui->btn_portal->setVisible(true);
               ui->btn_reportCrime->setVisible(false);
           }else{
               ui->btn_portal->setVisible(false);
               ui->btn_reportCrime->setVisible(true);
           }
        }
    });
    connect(ui->btn_register,&QPushButton::clicked,this,[](){
        Register  rg;
        rg.setWindowTitle("Register");
        rg.setModal(true);
        rg.exec();
    });
    connect(ui->btn_portal, &QPushButton::clicked, this, [this](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    for(int i = 2021; i >= 2000; i--){
        comboItems2.append(i);
    }
    ui->combo_year->addItems(toStringList(comboItems2));
    ui->combo_region->addItems(labels.toList());
    /*************page 2*********************/
    for(int i = 0; i < 101; i += 5){
        comboItems.append(i);
    }
    //ui->combo_show->setInsertPolicy(QComboBox::NoInsert);// no edit
    ui->combo_show->addItems(toStringList(comboItems));
    connect(ui->btn_home, &QPushButton::clicked, this, [this](){
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget2->setCurrentIndex(0);
    });

    ui->tblw_criminal->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tblw_criminal->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->combo_show, SIGNAL(currentIndexChanged(int)), SLOT(onComboCurrentIndexChanged(int)));
    connect(ui->btn_record, &QPushButton::clicked,this,[](){
        Record  rd1;
        rd1.setWindowTitle("Police Crime report");
        rd1.setModal(true);
        rd1.exec();
    });
    connect(ui->btn_reportCrime, &QPushButton::clicked,this,[](){
        Record  rd1;
        rd1.setWindowTitle("Police Crime report");
        rd1.setModal(true);
        rd1.exec();
    });
    // connect the buttons
    connect(ui->btn_add_team,&QPushButton::clicked, this , [this](){ ui->stackedWidget2->setCurrentIndex(1);});
    connect(ui->btn_view_item,&QPushButton::clicked, this , [this](){ ui->stackedWidget2->setCurrentIndex(2);});
    connect(ui->btn_view_crime,&QPushButton::clicked, this , [this](){ ui->stackedWidget2->setCurrentIndex(3);});
    connect(ui->btn_allocate_team,&QPushButton::clicked, this , [this](){ ui->stackedWidget2->setCurrentIndex(4);});
    connect(ui->btn_view_all,&QPushButton::clicked, this , [this](){ ui->stackedWidget2->setCurrentIndex(5);});
    connect(ui->btn_close_crime,&QPushButton::clicked, this , [this](){ ui->stackedWidget2->setCurrentIndex(6);});

}
MainWindow::~MainWindow()
{
    delete ui;
}

QStringList MainWindow::toStringList(const QList<int> list) {
    QStringList strings;
    foreach (const int &item, list) {
        strings.append(QString::number(item));
    }
    return strings;
}

void MainWindow::onComboCurrentIndexChanged(int num)
{
    ui->tblw_criminal->setRowCount(comboItems.at(num));
    int more_index = (ui->tblw_criminal->columnCount() - 1);
    for(int i = 0; i < comboItems.at(num); i++){
        edit_btn = new QPushButton("Report", this);
        edit_btn->setStyleSheet(btn_style);
       ui->tblw_criminal->setCellWidget(i,more_index, edit_btn);
       connect(edit_btn, &QPushButton::clicked, this,[](){
           Record  rd;
           rd.setWindowTitle("Police Crime report");
           rd.setModal(true);
           rd.exec();
       });
    }
}

void MainWindow::plotCustomPlot0()
{
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot0->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    QCPBars *regen = new QCPBars(ui->customPlot0->xAxis, ui->customPlot0->yAxis);
    QCPBars *nuclear = new QCPBars(ui->customPlot0->xAxis, ui->customPlot0->yAxis);
    QCPBars *fossil = new QCPBars(ui->customPlot0->xAxis, ui->customPlot0->yAxis);
    regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
    nuclear->setAntialiased(false);
    fossil->setAntialiased(false);
    regen->setStackingGap(1);
    nuclear->setStackingGap(1);
    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("Home Land Cases ");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));
    nuclear->setName("National cases");
    nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    nuclear->setBrush(QColor(250, 170, 20));
    regen->setName("International cases");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:
    nuclear->moveAbove(fossil);
    regen->moveAbove(nuclear);

    // prepare x axis with country labels:
    QVector<double> ticks;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot0->xAxis->setTicker(textTicker);
    ui->customPlot0->xAxis->setTickLabelRotation(60);
    ui->customPlot0->xAxis->setSubTicks(false);
    ui->customPlot0->xAxis->setTickLength(0, 4);
    ui->customPlot0->xAxis->setRange(0, 8);
    ui->customPlot0->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot0->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot0->xAxis->grid()->setVisible(true);
    ui->customPlot0->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot0->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot0->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot0->yAxis->setRange(0, 12.1);
    ui->customPlot0->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot0->yAxis->setLabel("Crime rate in Intensit/Region (2019)");
    ui->customPlot0->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot0->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot0->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot0->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot0->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot0->yAxis->setLabelColor(Qt::white);
    ui->customPlot0->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot0->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData, nuclearData, regenData;
    fossilData  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
    nuclearData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    regenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    fossil->setData(ticks, fossilData);
    nuclear->setData(ticks, nuclearData);
    regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot0->legend->setVisible(true);
    ui->customPlot0->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot0->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot0->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot0->legend->setFont(legendFont);
    ui->customPlot0->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void MainWindow::plotCustomPlot1()
{
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customPlot1->addGraph();
    ui->customPlot1->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot1->xAxis->setLabel("x");
    ui->customPlot1->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot1->xAxis->setRange(-1, 1);
    ui->customPlot1->yAxis->setRange(0, 1);
    ui->customPlot1->replot();
}

void MainWindow::plotCustomPlot2()
{
    // add two new graphs and set their look:
    ui->customPlot2->addGraph();
    ui->customPlot2->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    ui->customPlot2->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    ui->customPlot2->addGraph();
    ui->customPlot2->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
    // generate some points of data (y0 for first, y1 for second graph):
    QVector<double> x(251), y0(251), y1(251);
    for (int i=0; i<251; ++i)
    {
      x[i] = i;
      y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
      y1[i] = qExp(-i/150.0);              // exponential envelope
    }
    // configure right and top axis to show ticks but no labels:
    // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
    ui->customPlot2->xAxis2->setVisible(true);
    ui->customPlot2->xAxis2->setTickLabels(false);
    ui->customPlot2->yAxis2->setVisible(true);
    ui->customPlot2->yAxis2->setTickLabels(false);
    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(ui->customPlot2->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot2->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot2->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot2->yAxis2, SLOT(setRange(QCPRange)));
    // pass data points to graphs:
    ui->customPlot2->graph(0)->setData(x, y0);
    ui->customPlot2->graph(1)->setData(x, y1);
    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    ui->customPlot2->graph(0)->rescaleAxes();
    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
    ui->customPlot2->graph(1)->rescaleAxes(true);
    // Note: we could have also just called customPlot->rescaleAxes(); instead
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    ui->customPlot2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

void MainWindow::plotCustomPlot3()
{
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customPlot3->addGraph();
    ui->customPlot3->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot3->xAxis->setLabel("x");
    ui->customPlot3->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot3->xAxis->setRange(-1, 1);
    ui->customPlot3->yAxis->setRange(0, 1);
    ui->customPlot3->replot();
}

void MainWindow::plotCustomPlot4()
{
    // add two new graphs and set their look:
    ui->customPlot4->addGraph();
    ui->customPlot4->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    ui->customPlot4->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    ui->customPlot4->addGraph();
    ui->customPlot4->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
    // generate some points of data (y0 for first, y1 for second graph):
    QVector<double> x(251), y0(251), y1(251);
    for (int i=0; i<251; ++i)
    {
      x[i] = i;
      y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
      y1[i] = qExp(-i/150.0);              // exponential envelope
    }
    // configure right and top axis to show ticks but no labels:
    // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
    ui->customPlot4->xAxis2->setVisible(true);
    ui->customPlot4->xAxis2->setTickLabels(false);
    ui->customPlot4->yAxis2->setVisible(true);
    ui->customPlot4->yAxis2->setTickLabels(false);
    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(ui->customPlot4->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot4->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot4->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot4->yAxis2, SLOT(setRange(QCPRange)));
    // pass data points to graphs:
    ui->customPlot4->graph(0)->setData(x, y0);
    ui->customPlot4->graph(1)->setData(x, y1);
    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    ui->customPlot4->graph(0)->rescaleAxes();
    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
    ui->customPlot4->graph(1)->rescaleAxes(true);
    // Note: we could have also just called customPlot->rescaleAxes(); instead
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    ui->customPlot4->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

