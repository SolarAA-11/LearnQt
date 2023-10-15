#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_model = new QStringListModel(this);
    QStringList itemList;
    itemList << "Cow" << "Rooster" << "Lion" << "Hyena" << "Buffalo";
    m_model->setStringList(itemList);
    ui->listView->setModel(m_model);
}


Widget::~Widget()
{
    delete ui;
}


void Widget::on_showDataButton_clicked()
{
    auto rootItemIndex = QModelIndex();

    // Read data use index
    for(size_t i = 0; i < m_model->rowCount(QModelIndex()); ++i)
    {
        auto index = m_model->index(i, 0, rootItemIndex);
        auto data = index.data();
        qDebug() << data.toString();
    }
}

