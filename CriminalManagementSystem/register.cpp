#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    //set the access levels
    ui->spinBox->setMaximum(5);
    ui->spinBox->setMinimum(1);
    // start db connection
    hdl_register = new SqliteHandler(db_name, conn_name);//setup database connection
    if(!hdl_register->createTable(crt_table)){//create table if not exists
            QMessageBox::critical(nullptr, QObject::tr("Critical Error"),
                              QObject::tr("Unable to create a table or the table already exists\n\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    connect(ui->btn_ok, &QPushButton::clicked,this, &Register::onOKClicked);
    connect(ui->btn_cancel,&QPushButton::clicked,this,&Register::onCancelClicked);
    connect(ui->spinBox,SIGNAL(valueChanged(int)), this,SLOT(onValueChanged(int)));
}

Register::~Register()
{
    delete hdl_register;
    delete ui;
}
void Register::onValueChanged(int val){
    access_level = val;
}
void Register::onOKClicked(){
    fullname = ui->le_name->text();
    username = ui->le_username->text();
    password = ui->le_password->text();
    confirm_password = ui->le_confirm_password->text();
    security_number = ui->le_number->text();
    access_level = ui->spinBox->value();
    if(QString::compare(password, confirm_password, Qt::CaseSensitive) > 0)
    {
        ui->lbl_password->setText("Passwords do not match");
        ui->le_confirm_password->clear();
        _exit = false;
    }
    if(fullname.isEmpty() || username.isEmpty() || password.isEmpty() || confirm_password.isEmpty() || security_number.isEmpty()){
        ui->lbl_password->setText("Make sure all the fields are filled!!!");
        _exit = false;
    }else{
        if(saveUser()){// save the  user details saveUser();// save the  user details
             _exit = true;
            Register::close();
        }else{
            _exit = false;
        }
    }
}

bool Register::saveUser()
{
    // select username
    SelectModel s;
    s.select("user_name")
            .where(column("user_name") == username.toStdString() or column("security_number") == security_number.toStdString())
            .from("users");
    QSqlQuery query = hdl_register->selectCommand(QString::fromStdString(s.str()));
    int numberRows = 0;
    if(query.last()){
        numberRows = query.at() + 1;
        query.first();
        query.previous();
    }
    if(numberRows == 0){
        // create a model to save data
        InsertModel i;
        i.insert("full_name", fullname.toStdString())
                ("security_number",security_number.toStdString())
                ("user_name",username.toStdString())
                ("password",password.toStdString())
                ("access_level",access_level).into("users");
        if(hdl_register->execCommand(QString::fromStdString(i.str()))){
            return true;
        }else{
            return false;
        }
    }else{
        ui->lbl_password->setText("username already used");
        ui->le_username->clear();
        return false;
    }
}

void Register::closeEvent(QCloseEvent *event)
{
    if(_exit){
        event->accept();
    }else{
        event->ignore();
    }
}

void Register::onCancelClicked(){
    _exit = true;
    Register::close();// close the window
}
