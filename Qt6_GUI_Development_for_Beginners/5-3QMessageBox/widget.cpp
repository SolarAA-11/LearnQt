#include "widget.h"
#include "./ui_widget.h"

#include <QDebug>
#include <QMessageBox>

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
//    qDebug() << "You clicked on the button";
//    QMessageBox messageBox;
//    messageBox.setMinimumSize(700, 200);
//    messageBox.setWindowTitle("Message Title");
//    messageBox.setText("Somethinig Happen");
//    messageBox.setInformativeText("Do you want to do something about it?");
//    messageBox.setIcon(QMessageBox::Critical);
//    messageBox.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
//    messageBox.setDefaultButton(QMessageBox::Cancel);

//    int ret = messageBox.exec();

    int ret = QMessageBox::question(this, "Message Title",
                                    "Something happened. Do you want to do something about it",
                                    QMessageBox::Ok|QMessageBox::Cancel);
    if (ret == QMessageBox::Ok) {
        qDebug() << "User clicked on OK";
    } else if (ret == QMessageBox::Cancel) {
        qDebug() << "User clicked on Cancel";
    }
}

