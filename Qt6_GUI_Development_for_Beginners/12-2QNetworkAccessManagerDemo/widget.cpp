#include "widget.h"
#include "./ui_widget.h"

#include <QNetworkReply>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_buffer = new QByteArray();

    // Init Network Access Manager
    m_netManager = new QNetworkAccessManager(this);

    // Init request
    QNetworkRequest request;
    request.setUrl(QUrl("https://www.github.com"));

    // Send request
    m_netReply = m_netManager->get(request);

    // Connect Reply's signals to slots
    connect(m_netReply, &QNetworkReply::readyRead, this, &Widget::data_ready_to_read);
    connect(m_netReply, &QNetworkReply::finished, this, &Widget::date_read_finished);
}

Widget::~Widget()
{
    delete m_buffer;
    delete ui;
}

void Widget::data_ready_to_read()
{
    qDebug() << "Get some information";
    m_buffer->append(m_netReply->readAll());
}

void Widget::date_read_finished()
{
    if(m_netReply->error())
    {
        qDebug() << "Error: " << QString(*m_buffer);
    } else
    {
        ui->textEdit->setPlainText(QString(*m_buffer));
    }
}

