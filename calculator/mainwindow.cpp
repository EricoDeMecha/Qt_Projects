#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLineEdit *display = ui->lineEdit;
    display->setAlignment(Qt::AlignRight);
    QFont  font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);


    connect(ui->push0, &QPushButton::clicked , [this]{  QString text0 = ui->lineEdit->text() + ui->push0->text(); ui->lineEdit->setText(text0); });
    connect(ui->push1, &QPushButton::clicked , [this]{  QString text1 = ui->lineEdit->text()+ ui->push1->text(); ui->lineEdit->setText(text1); });
    connect(ui->push2, &QPushButton::clicked , [this]{  QString text2 = ui->lineEdit->text()+ ui->push2->text(); ui->lineEdit->setText(text2); });
    connect(ui->push3, &QPushButton::clicked , [this]{  QString text3 = ui->lineEdit->text()+ ui->push3->text(); ui->lineEdit->setText(text3); });
    connect(ui->push4, &QPushButton::clicked , [this]{  QString text4 = ui->lineEdit->text()+ ui->push4->text(); ui->lineEdit->setText(text4); });
    connect(ui->push5, &QPushButton::clicked , [this]{  QString text5 = ui->lineEdit->text()+ ui->push5->text(); ui->lineEdit->setText(text5); });
    connect(ui->push6, &QPushButton::clicked , [this]{  QString text6 = ui->lineEdit->text()+ ui->push6->text(); ui->lineEdit->setText(text6); });
    connect(ui->push7, &QPushButton::clicked , [this]{  QString text7 = ui->lineEdit->text()+ ui->push7->text(); ui->lineEdit->setText(text7); });
    connect(ui->push8, &QPushButton::clicked , [this]{  QString text8 = ui->lineEdit->text()+ ui->push8->text(); ui->lineEdit->setText(text8); });
    connect(ui->push9, &QPushButton::clicked , [this]{  QString text9 = ui->lineEdit->text()+ ui->push9->text(); ui->lineEdit->setText(text9); });
    connect(ui->pushdot, &QPushButton::clicked , [this]{  QString text11 = ui->lineEdit->text() + ui->pushdot->text(); ui->lineEdit->setText(text11); });
    connect(ui->pushdiv, &QPushButton::clicked , [this]{  QString text12 = ui->lineEdit->text()+ ui->pushdiv->text(); ui->lineEdit->setText(text12); });
    connect(ui->pushadd, &QPushButton::clicked , [this]{  QString text13 = ui->lineEdit->text()+ ui->pushadd->text(); ui->lineEdit->setText(text13); });
    connect(ui->pushx, &QPushButton::clicked , [this]{  QString text14 = ui->lineEdit->text()+ ui->pushx->text(); ui->lineEdit->setText(text14); });
    connect(ui->pushmin, &QPushButton::clicked , [this]{  QString text15 = ui->lineEdit->text() + ui->pushmin->text(); ui->lineEdit->setText(text15); });

    connect(ui->pushequal , &QPushButton::clicked ,[this]{
        // QRegExp delim("(\\+|\\-|\\/|\\X)");
         QString str =  ui->lineEdit->text();
         //QStringList strString = str.split(delim);
         QScriptEngine  expresion;
         double result = expresion.evaluate(str).toNumber();
         ui->lineEdit->setText(QString::number(result));
         QString plainTextCon = ui->plainTextEdit->toPlainText();
         ui->plainTextEdit->setPlainText(plainTextCon + "\n" + str +" = "+ QString::number(result));
    });
    connect(ui->DEL , &QPushButton::clicked , [this]{
         QString str =  ui->lineEdit->text();
        str.chop(1);
        if(str.isEmpty())
        {
            str= "0";
        }
        ui->lineEdit->setText(str);
    });
    connect(ui->EXIT,SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->AC, &QPushButton::clicked , [this]{
        ui->lineEdit->clear();
    });
}
MainWindow::~MainWindow()
{
    delete ui;

}
