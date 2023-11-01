#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap pixmap("://images/a.png");
    ui->iconButton->setIcon(pixmap);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    qDebug() << "Button Clicked";
}
