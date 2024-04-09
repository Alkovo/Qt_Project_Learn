#include "widget.h"
#include "./ui_widget.h"
#include<QPushButton>
#include"form.h"
#include<QString>
#include<QDebug>
#include<QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->new_Window = new Form();
    connect(this->new_Window,&Form::Back,this,[=](){
        new_Window->hide();
        this->show();
    });
    connect(ui->pushButton_Cancel,&QPushButton::clicked,this,[=](){
        close();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_login_clicked()
{
    QString Name = ui->lineEdit_Name->text();
    QString PassWord = ui->lineEdit_PassWord->text();

    if(Name == "admire" && PassWord == "123456"){
    this->hide();
    this->new_Window->show();
    }else{
        QMessageBox::information(this,"输入有误","请确认账号密码是否正确");
    }
}

