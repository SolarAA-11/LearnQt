#include "widget.h"
#include "ui_widget.h"

#include <QInputDialog>
#include <QDebug>
#include <QDir>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(
                this,
                "QInputDialog::getText()",
                "User Name",
                QLineEdit::Normal,
                QDir::home().dirName(),
                &ok);

    qDebug() << text;
}

