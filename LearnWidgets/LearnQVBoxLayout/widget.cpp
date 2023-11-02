#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout *layout = new QVBoxLayout();
    QPushButton *button1 = new QPushButton("Button 1");
    layout->addWidget(button1);
    setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

