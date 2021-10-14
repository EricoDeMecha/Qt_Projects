#include "record.h"
#include "ui_record.h"

Record::Record(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Record)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    image.load(":/assets/police_report.png");

    ui->image_view->setScene(scene);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    ui->image_view->show();
    // verify the date
    connect(ui->le_date, &QLineEdit::editingFinished, this,[this](){
        QString _date = ui->le_date->text();// get teh line

    });
    // age to only line numbers btw 10 and 120
    ui->le_age->setValidator(new QIntValidator(10, 120, this));
    ui->tbl_records->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tbl_records->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Record::~Record()
{
    delete ui;
}
