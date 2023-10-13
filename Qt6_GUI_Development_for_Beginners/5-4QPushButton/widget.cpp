#include "widget.h"
#include "./ui_widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Clicked Signal
    QFont btn1_font("Times", 20, QFont::Bold);
    QPushButton *btn1 = new QPushButton("Button1", this);
    btn1->setMinimumSize(200, 100);
    btn1->setFont(btn1_font);
    connect(btn1, &QPushButton::clicked, [=](){
        qDebug() << "Button 1 clicked";
    });

    // pressed and released signals
    QFont btn2_font("Times", 20, QFont::Bold);
    QPushButton *btn2 = new QPushButton("Button2", this);
    btn2->setMinimumSize(200, 100);
    btn2->move(205, 0);
    btn2->setFont(btn2_font);
    connect(btn2, &QPushButton::pressed, [=](){
        qDebug() << "Button 2 pressed";
    });
    connect(btn2, &QPushButton::released, [=](){
        qDebug() << "Button 2 released";
    });

}

Widget::~Widget()
{
    delete ui;
}

