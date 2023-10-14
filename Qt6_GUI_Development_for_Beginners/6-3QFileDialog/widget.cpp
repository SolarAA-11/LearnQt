#include "widget.h"
#include "./ui_widget.h"

#include <QFileDialog>

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
//    QString dir = QFileDialog::getExistingDirectory(this, "Open Directory",
//                                                    QString(),
//                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
//    qDebug() << dir;

    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Open File",
                                                    QString(),
                                                    "Images (*.png, *.xpm, *.jpg)");
    qDebug() << fileName;
}

