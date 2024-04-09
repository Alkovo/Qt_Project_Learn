## 这是一个个人Qt学习项目用来演示qt信号与槽函数
### 主要包括登录界面和主界面
登录界面头文件
```
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "form.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::Widget *ui;
    Form *new_Window;
};
#endif // WIDGET_H
```

登录界面头文件中需要包含主界面的类，并在头文件中声明***new_Window**，同时也是为了接收到主界面传回的**Back**信号。  
在头文件中声明pushButton_login按钮控件绑定的槽函数（由qtcreator完成）并在.cpp文件中实现。
***
主界面头文件
```
#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:
    Ui::Form *ui;

signals:
    void Back();

private slots:
    void on_pushButton_Back_clicked();
};

#endif // FORM_H
```
声明一个**Back**信号由登陆界面接收，在头文件中声明pushButton_Back按钮控件绑定的槽函数（由qtcreator完成）并在.cpp文件中实现。

### 登陆界面
登录界面包含两个lineEdit控件用来匹配输入与设置的字符  
一个QPushButton控件绑定点击事件与槽函数，若输入字符与匹配字符相同则隐藏登录界面显示主界面

```
this->new_Window = new Form();//在头文件中声明在.cpp文件中创建主界面窗口

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
```

