#include "widget.h"
#include "./ui_widget.h"

#include <QVBoxLayout>
#include "button.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout *layout = new QVBoxLayout();

    Button *button = new Button();
    button->setText("Push Button");
    layout->addWidget(button);
    setLayout(layout);

    connect(button, &Button::clicked, [=](){
        qDebug() << "Button is clicked";
    });
}

Widget::~Widget()
{
    delete ui;
}

