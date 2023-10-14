#include "widget.h"
#include "./ui_widget.h"

#include <QDebug>
#include <QPalette>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label->setAutoFillBackground(true);

    QPalette palette = ui->label->palette();

    palette.setColor(QPalette::Window, Qt::blue);
    palette.setColor(QPalette::WindowText, Qt::red);

    ui->label->setPalette(palette);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_activeButton_clicked()
{
    qDebug() << "Active Button Clicked";

    auto activeButtonColorGroup = ui->activeButton->palette().currentColorGroup();
    auto disabledButtonColorGroup = ui->disabledButton->palette().currentColorGroup();

    qDebug() << "Active Button Color Group: " << activeButtonColorGroup;
    qDebug() << "Disabled Button Color Group: " << disabledButtonColorGroup;
}


void Widget::on_disabledButton_clicked()
{
    qDebug() << "Disabled Button Clicked";
}

