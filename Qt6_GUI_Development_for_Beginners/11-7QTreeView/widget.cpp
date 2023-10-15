#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Using QFileSystemModel
//    QString path("C:/");

//    m_dir_model = new QFileSystemModel();
//    m_dir_model->setFilter(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);
//    m_dir_model->setRootPath(path);

//    ui->treeView->setModel(m_dir_model);
//    ui->listView->setModel(m_dir_model);

    // Using QStandardItemModel
    m_standard_model = new QStandardItemModel();

    QStandardItem *parentItem = m_standard_model->invisibleRootItem();
    for(size_t i = 0; i < 4; ++i)
    {
        QStandardItem *item = new QStandardItem();
        item->setText(QString("Item %1").arg(i));
        parentItem->appendRow(item);
        parentItem = item;
    }
    ui->treeView->setModel(m_standard_model);
    ui->listView->setModel(m_standard_model);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_readDataButton_clicked()
{

}

