#include "widget.h"
#include "./ui_widget.h"

#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap my_image(":/DPlayer.png");
    ui->imageLabel->setPixmap(my_image.scaled(400, 400));
}

Widget::~Widget()
{
    delete ui;
}

