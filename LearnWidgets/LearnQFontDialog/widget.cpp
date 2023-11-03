#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QFontDialog>

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
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this->font(), this);
    qDebug() << font;
}

