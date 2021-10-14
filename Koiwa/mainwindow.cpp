#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "db_connection.h"

//global  sql object
db_connection _db;
QString filename;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _db.connect_db();
    showCharts();
    connect(ui->SUploadPass , &QPushButton::clicked , [this] {
        QString temp  = QFileDialog::getOpenFileName(this, "PassPort",QDir::currentPath(),"PNG files (*.png)");
        filename = temp;
        QPixmap  image(temp);
        QLabel *_label = ui->showImage;
        _label->setFixedWidth(150);
        _label->setFixedHeight(200);
         _label->setPixmap(image);
        _label->setScaledContents(true);
            });
}

//sets the current widget of the stackedWidget

void MainWindow::changeWidget(int num)
{
    QStackedWidget *_widget=  ui->stackedWidget;
    _widget->setCurrentIndex(num);
}

void MainWindow::showCharts()
{
    //hide the admission buttons as window opens
    QPushButton *button1 = ui->students;  button1->hide();
    QPushButton *button2 = ui->tstaff;  button2->hide();
    QPushButton *button3 = ui->ntstaff;  button3->hide();

    QPieSeries *series = new QPieSeries();

    series->append("Students" , 1000);
     series->append("Teachers" , 100);
      series->append("Non-teaching staff" , 80);

    QPieSlice *slice = series->slices().at(1);
    slice->setExploded();
    slice->setLabelVisible();
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);

    QChart  *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("School Population");
    chart->legend()->hide();

    QChartView *chartview = new QChartView(chart);
    ui->disp1->size();
    chartview->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    chartview->setParent(ui->disp1);
}

void MainWindow::getWindowData()
{
    //students details
    QString  name = ui->name->text();
    int age = ui->age->text().toInt();
    QString primarySchool  = ui->primaryschool->text();
    int index_no = ui->indexno->text().toInt();
    int marks  = ui->marks->text().toInt();
    QString fname = ui->fathername->text();
    int fid = ui->Fid->text().toInt();
    int FPhoneNo = ui->FPhoneNo->text().toInt();
    QString mname = ui->mothername->text();
    int mid = ui->Mid->text().toInt();
    int MPhoneNo = ui->MPhoneNO->text().toInt();
    QString Gname = ui->guardianName->text();
    int gid = ui->Gid->text().toInt();
    int GPhoneNo = ui->GPhoneNo->text().toInt();
    QString  county = ui->county->text();
    QString  subcounty = ui->subcounty->text();
    QString residence = ui->residence->text();
    // ,LOAD_FILE('" + filename + "')
    QString scommand = "INSERT INTO students(name ,age , primary_school , index_no , Marks , Fathers_name , fid , fphone_no , mothers_name , mid , mphone_no , Guardian_name ,gid , gphone_no , county , subcounty , residence ) VALUES('"+name+"',"+ QString::number(age) +",'"+ primarySchool+"',"+  QString::number(index_no) + ","+ QString::number(marks)+",'"+ fname+ "'," + QString::number(fid)+ "," +QString::number(FPhoneNo) +",'"+ mname+ "',"+ QString::number(mid) +","+ QString::number(MPhoneNo) + ",'" + Gname+ "',"+ QString::number(gid)+","+ QString::number(GPhoneNo)+",'"+ county + "','"+ subcounty +"','"+ residence+ "');";
    _db.execute_query(scommand);
}

void MainWindow::getWindowDataTstaff()
{
  QString tname = ui->tname->text();
  QString tsc_no = ui->Ttscno->text();
  QString  Bank_ac = ui->tbankac_no->text();
  int tid = ui->tid_no->text().toInt();
  int phone_no = ui->tphone_no->text().toInt();

  QString tcommand = "INSERT INTO TStaff (name ,TSC_no, Bank_AC_no, ID_no, phone_no) VALUES ('" +tname +"','"+ tsc_no +"','"+ Bank_ac +"',"+ QString::number( tid ) +","+ QString::number(phone_no)+");";

  _db.execute_query(tcommand);
}

void MainWindow::getWindowDataNTstaff()
{
    QString ntname = ui->NTname->text();
    int ntid = ui->NTid->text().toInt();
    int ntphone_no = ui->NTphone_no->text().toInt();
    QString ntbank_ac = ui->NTPhone_no->text();

    QString  ntcommand = "INSERT INTO NTStaff ( name, ID_no, phone_no, Bank_ac_no) VALUES ('"+ ntname +"'," + QString::number(ntid) +","+ QString::number(ntphone_no)+",'"+ ntbank_ac+"');";

    _db.execute_query(ntcommand);
}

void MainWindow::display_add()
{
    QPushButton *button1 = ui->students;
    QPushButton *button2 = ui->tstaff;
    QPushButton *button3 = ui->ntstaff;
    if(button1->isVisible() ||  button2->isVisible() || button3->isVisible() )
    {
       button1->hide();
       button2->hide();
       button3->hide();
    }
    else
    {
        button1->show();
        button2->show();
        button3->show();
    }
}

void MainWindow::on_admission_clicked()
{
    display_add();
}

void MainWindow::on_students_clicked()
{
     changeWidget(1);
}

void MainWindow::on_pushButton_2_clicked()
{
     changeWidget(0);
}

void MainWindow::on_Thome_clicked()
{
    changeWidget(0);
}

void MainWindow::on_SHome_clicked()
{
    changeWidget(0);
}

void MainWindow::on_NtCancel_clicked()
{
   changeWidget(0);
}

void MainWindow::on_TCancel_clicked()
{
   changeWidget(0);
}

void MainWindow::on_tstaff_clicked()
{
   changeWidget(2);
}

void MainWindow::on_ntstaff_clicked()
{
   changeWidget(3);
}

void MainWindow::on_Scancel_clicked()
{
    changeWidget(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SSubmit_clicked()
{
   getWindowData();
}


void MainWindow::on_NTSubmit_clicked()
{
    getWindowDataNTstaff();
}

void MainWindow::on_ButtonTstaff_clicked()
{
    getWindowDataTstaff();
}
