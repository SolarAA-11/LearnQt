#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_model = new QStandardItemModel(4, 4);

    for(size_t i = 0; i < m_model->rowCount(); ++i)
    {
        for(size_t j = 0; j < m_model->columnCount(); ++j)
        {
            QStandardItem *item = new QStandardItem(QString("Row %1 Col %2").arg(i).arg(j));
            m_model->setItem(i, j, item);
        }
    }

    ui->tableView->setModel(m_model);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_readDataButton_clicked()
{
    auto rootItemIndex = QModelIndex();

    for(size_t row = 0; row < m_model->rowCount(); ++row)
    {
        for(size_t col = 0; col < m_model->columnCount(); ++col)
        {
            auto index = m_model->index(row, col, rootItemIndex);
            QString data = m_model->data(index, Qt::DisplayRole).toString();
            qDebug() << "Row: " << row << ", Col: " << col << ", Data: " << data;
        }
        qDebug() << "---";
    }
}

