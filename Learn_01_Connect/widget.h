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
