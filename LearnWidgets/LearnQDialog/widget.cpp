#include "widget.h"
#include "ui_widget.h"

#include <QDialog>
#include <QIcon>
#include <QPixmap>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_dialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout();

    QPushButton *btn1 = new QPushButton("OK");
    QPushButton *btn2 = new QPushButton("Reject");
    QPushButton *btn3 = new QPushButton("Done");

    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);

    m_dialog->setLayout(layout);

    connect(btn1, &QPushButton::clicked, m_dialog, &QDialog::accept);
    connect(btn2, &QPushButton::clicked, m_dialog, &QDialog::reject);
    connect(btn3, &QPushButton::clicked, [=](){
        m_dialog->done(QDialog::Accepted);
    });

    m_modelessDialog = new QDialog(this);
    connect(m_modelessDialog, &QDialog::finished, [=](){
        m_modelessDialogPosition = m_modelessDialog->pos();
        qDebug() << m_modelessDialogPosition;
    });

}



Widget::~Widget()
{
    delete ui;
}


void Widget::on_openDialogButton_clicked()
{
    int returnValue = m_dialog->exec();
    qDebug() << returnValue;
}


void Widget::on_showModalDialogButton_clicked()
{
    m_dialog->setModal(true);
    m_dialog->show();
}


void Widget::on_showModelessDialogButton_clicked()
{
    m_modelessDialog->move(m_modelessDialogPosition);
    m_modelessDialog->show();
}

