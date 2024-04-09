#include "form.h"
#include "ui_form.h"
#include<QMessageBox>

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    //connect(ui->pushButton_Back,SIGNAL(clicked(bool)),this,SIGNAL(Back()));

}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_Back_clicked()
{
    QMessageBox::StandardButton result = QMessageBox::question(this, "确认退出", "是否确认退出", QMessageBox::No|QMessageBox::Yes,QMessageBox::No);
    if (result == QMessageBox::Yes) {
        emit Back();
    }
}

