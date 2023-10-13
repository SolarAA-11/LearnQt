#include "widget.h"
#include "./ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Earth");
    ui->comboBox->addItem("Venus");

    QStringList items;
    items << "Mars" << "Pluton" << "Saturn";
    ui->comboBox->addItems(items);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_captureButton_clicked()
{
    qDebug() << "Current Text: " << ui->comboBox->currentText()
             << "Current Index: " << QString::number(ui->comboBox->currentIndex());
}


void Widget::on_setButton_clicked()
{
    ui->comboBox->setCurrentIndex(3);
}


void Widget::on_listButton_clicked()
{
    int itemCount = ui->comboBox->count();
    for(int i = 0;i < itemCount;++i) {
        qDebug() << "Index " << QString::number(i) << " : " << ui->comboBox->itemText(i);
    }
}

