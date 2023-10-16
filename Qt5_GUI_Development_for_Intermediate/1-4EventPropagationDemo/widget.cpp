#include "widget.h"
#include "./ui_widget.h"

#include <QVBoxLayout>
#include <QDebug>

#include "childbutton.h"
#include "childlineedit.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ChildButton *button = new ChildButton();
    button->setText("Button");

    ChildLineEdit *lineEdit = new ChildLineEdit();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(button);
    layout->addWidget(lineEdit);
    setLayout(layout);

    connect(button, &ChildButton::clicked, [=](){
        qDebug() << "Child Button Clicked";
    });
}

Widget::~Widget()
{
    delete ui;
}

