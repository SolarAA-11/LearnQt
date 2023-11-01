#include "widget.h"
#include "ui_widget.h"

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


void Widget::on_doubleSpinBox_4_valueChanged(const QString &arg1)
{
    QString labelContent = QString("String Content: %1").arg(arg1);
    ui->stringValueChangedLabel->setText(labelContent);
}


void Widget::on_doubleSpinBox_4_valueChanged(double arg1)
{
    QString labelContent = QString("Double Content: %1").arg(arg1);
    ui->doubleValueChangedLabel->setText(labelContent);
}


void Widget::on_doubleSpinBox_5_valueChanged(double arg1)
{
    Q_UNUSED(arg1);

    ui->plainTextLabel->setText(ui->doubleSpinBox_5->text());
    ui->cleanTextLabel->setText(ui->doubleSpinBox_5->cleanText());
}

