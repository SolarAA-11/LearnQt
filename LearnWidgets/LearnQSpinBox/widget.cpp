#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_spinBox_valueChanged(const QString &arg1)
{
    if(arg1 == "Automation")
    {
        qDebug() << "Automation";
    }
}

