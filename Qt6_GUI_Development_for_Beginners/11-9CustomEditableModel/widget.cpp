#include "widget.h"
#include "./ui_widget.h"

#include "customtablemodel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_model = new CustomTableModel(this);

    ui->listView->setModel(m_model);
    ui->treeView->setModel(m_model);
    ui->tableView->setModel(m_model);
}

Widget::~Widget()
{
    delete ui;
}

