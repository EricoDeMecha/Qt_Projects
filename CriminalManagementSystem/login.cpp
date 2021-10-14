#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->btn_ok, &QPushButton::clicked,this,&Login::onOKClicked);
    connect(ui->btn_cancel,&QPushButton::clicked,this,&Login::onCancelClicked);
    hdl = new SqliteHandler(db_name, conn_name);// create a database table
}

Login::~Login()
{
    delete hdl;
    delete ui;
}

void Login::onOKClicked(){
    username = ui->le_username->text();
    password = ui->le_password->text();
    if(username.isEmpty() || password.isEmpty()){
        ui->lbl_error->setText("Make use to fill out all the fields!!");
        _exit = false;
        Login::close();
    }else{
        if(verifyUser()){
            _exit = true; _uExit = true;
            Login::close();
        }else{
            _exit = false;
        }
    }
}

bool Login::verifyUser()
{
    SelectModel s;
    s.select("user_name","password","access_level")
            .where(column("user_name") == username.toStdString() and column("password") == password.toStdString())
            .from("users");
    QSqlQuery query = hdl->selectCommand(QString::fromStdString(s.str()));
    int numberRows = 0;
    if(query.last()){
        numberRows = query.at() + 1;
        query.first();
        query.previous();
    }
    if(numberRows == 0){
         ui->lbl_error->setText("username or password is wrong");
         ui->le_username->clear();// clear the username  field
         ui->le_password->clear();// clear the password field
         return false;
    }else{
        // user successfully logged in
        if(query.first()){
            int fieldNo = query.record().indexOf("access_level");
            access_level =  query.value(fieldNo).toInt();// select the access level
        }
        return true;
    }
}

void Login::closeEvent(QCloseEvent *event)
{
    if(_exit){
        event->accept();
    }else{
        event->ignore();
    }
}

void Login::onCancelClicked(){
    _uExit = !((username.isEmpty() || password.isEmpty()));
    _exit = true;
    Login::close();
}
