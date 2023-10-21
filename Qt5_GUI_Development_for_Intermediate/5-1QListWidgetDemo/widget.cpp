 #include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStringList fruitList;
    fruitList << "Apple" << "Avocado" << "Banana"
              << "Blueberries" << "Cucumber" << "EggFruit"
              << "Fig" << "Grape" << "Mango" << "Pear"
              << "Pineapple" << "Watermellon";

    for(const QString &fruitName: fruitList)
    {
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        item->setData(Qt::DisplayRole, fruitName);

        QString iconFilePath = QString(":/images/%1.png").arg(fruitName.toLower());
        QIcon icon(iconFilePath);
        item->setIcon(icon);
    }

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_readDataButton_clicked()
{
    // Read current selected item's data from List Widget
    // And print them in the console

//    QListWidgetItem *item = ui->listWidget->currentItem();
//    qDebug() << "Item display text: " << item->text();

    // Show multiple selected items' information

    QList<QListWidgetItem*> selectedItemList = ui->listWidget->selectedItems();
    for(auto item: selectedItemList)
    {
        qDebug() << item->text();
    }
}

