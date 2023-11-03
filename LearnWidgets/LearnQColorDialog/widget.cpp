#include "widget.h"
#include "ui_widget.h"

#include <QColorDialog>
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


void Widget::on_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(
                Qt::white,
                this,
                "Choose Color",
                QColorDialog::ShowAlphaChannel
    );
    qDebug() << color;
}

