#include "widget.h"
#include "./ui_widget.h"

#include <QListWidget>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QListWidget *widget = ui->listWidget;
    widget->addItem("Item 1");
    widget->addItem("Item 2");
    QStringList items;
    items << "Item 3" << "Item 4" << "Item 5";
    widget->addItems(items);

    widget->setSelectionMode(QAbstractItemView::ExtendedSelection);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_addItemButton_clicked()
{
    ui->listWidget->addItem("Another Item");
}

void Widget::on_removeItemButton_clicked()
{
    QListWidget *listWidget = ui->listWidget;
    listWidget->takeItem(listWidget->currentRow());
}

void Widget::on_selectedItemButton_clicked()
{
    auto list = ui->listWidget->selectedItems();
    for(auto item: list) {
        qDebug() << "Selected Item: " << item->text() << " , row number id : " << ui->listWidget->row(item);
    }
}

