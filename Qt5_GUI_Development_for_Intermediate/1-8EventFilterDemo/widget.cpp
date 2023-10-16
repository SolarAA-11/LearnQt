#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_filter = new KeyboardFilter(this);

    ui->lineEdit->installEventFilter(m_filter);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    // remove LineEdit's EventFilter
    ui->lineEdit->removeEventFilter(m_filter);
}

