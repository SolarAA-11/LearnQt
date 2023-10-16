#include "widget.h"
#include "./ui_widget.h"

#include <QVBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_button = new DoubleClickableButton(this);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_button);
    setLayout(layout);

    connect(m_button, &DoubleClickableButton::doubleClicked, [=](){
        qDebug() << "Double Clicked";
    });
}

Widget::~Widget()
{
    delete ui;
}

