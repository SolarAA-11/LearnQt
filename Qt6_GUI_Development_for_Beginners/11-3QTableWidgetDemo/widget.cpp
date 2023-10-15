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
    for(size_t i = 0; i < ui->tableWidget->rowCount(); ++i)
    {
        for(size_t j = 0; j < ui->tableWidget->columnCount(); ++j)
        {
            auto item_ptr = ui->tableWidget->item(i, j);
            if(item_ptr != nullptr)
            {
                QVariant data = item_ptr->data(Qt::DisplayRole);
                qDebug() << data;
            } else
            {
                qDebug() << "Data does not exist";
            }
        }
    }
}


void Widget::on_setItemsButton_clicked()
{
    ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());

    auto newItem = new QTableWidgetItem("Hello");
    ui->tableWidget->setItem(
        ui->tableWidget->rowCount() - 1,
        ui->tableWidget->rowCount() - 1,
        newItem);
}

