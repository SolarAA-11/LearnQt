#include "widget.h"
#include "./ui_widget.h"

#include <QButtonGroup>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QButtonGroup *group = new QButtonGroup(this);
    group->addButton(ui->windowsCheckBox);
    group->addButton(ui->macCheckBox);
    group->addButton(ui->linuxCheckBox);
    group->setExclusive(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_grabDataButton_clicked()
{

}


void Widget::on_setDataButton_clicked()
{

}

