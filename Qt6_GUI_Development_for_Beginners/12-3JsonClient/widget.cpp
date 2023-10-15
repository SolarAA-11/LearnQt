#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_net_manager(new QNetworkAccessManager(this))
    , m_net_reply(nullptr)
    , m_buffer(new QByteArray)
{
    ui->setupUi(this);

    // Send Request

    // Fetch
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_fetchButton_clicked()
{

}

