#include "widget.h"
#include "./ui_widget.h"

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


void Widget::on_listItemsButton_clicked()
{
    for(size_t i = 0;i < ui->listWidget->count();++i)
    {
        auto item_ptr = ui->listWidget->item(i);
        item_ptr->setToolTip("Tooltip" + QString::number(i));
        QVariant data = item_ptr->data(Qt::ToolTipRole);
        qDebug() << data.toString();
    }
}


void Widget::on_addItemButton_clicked()
{
    ui->listWidget->addItem("Hello World");
}

