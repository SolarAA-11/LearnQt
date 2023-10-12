#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // String Notation Connect
//    connect(ui->myButton, SIGNAL(clicked(bool)),
//            this, SLOT(changeText()));
    // Function Notation
//    connect(ui->myButton, &QPushButton::clicked,
//            this, &Widget::changeText);
    // Lambda Notation
    connect(ui->myButton, &QPushButton::clicked, [=](){
        ui->label->setText("Some other text");
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeText()
{
    ui->label->setText("Some other text");
}

