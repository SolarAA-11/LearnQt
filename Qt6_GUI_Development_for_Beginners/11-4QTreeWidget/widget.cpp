#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Set TreeWidget Column Count to 2
    ui->treeWidget->setColumnCount(2);

    // Set TreeWidget Column Header Content
    ui->treeWidget->setHeaderLabels(QStringList() << "ID" << "Name");

    // Add Data
    QTreeWidgetItem *treeItem1 = new QTreeWidgetItem(ui->treeWidget);
    treeItem1->setText(0, "11");
    treeItem1->setText(1, "Snow");

    QTreeWidgetItem *treeItem2 = new QTreeWidgetItem(ui->treeWidget);
    treeItem2->setText(0, "22");
    treeItem2->setText(1, "David");

    // Add Child Data
    QTreeWidgetItem *treeItem3 = new QTreeWidgetItem(); // Don'e specify parent widget
    treeItem3->setText(0, "33");
    treeItem3->setText(1, "Steve");

    treeItem2->addChild(treeItem3);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_listItemsButton_clicked()
{
    for(size_t i = 0; i < ui->treeWidget->topLevelItemCount(); ++i)
    {
        auto item = ui->treeWidget->topLevelItem(i);
        if(item != nullptr)
        {
            qDebug() << item->data(0, Qt::DisplayRole).toString() << ","
                     << item->data(1, Qt::DisplayRole).toString();

            // Look for children
            for(size_t j = 0; j < item->childCount(); ++j)
            {
                auto childItem = item->child(j);
                if(childItem != nullptr)
                {
                    qDebug() << "---"
                             << childItem->data(0, Qt::DisplayRole).toString() << ","
                             << childItem->data(1, Qt::DisplayRole).toString();
                }
            }
        }
    }
}

