#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            ui->progressBar, SLOT(setValue(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            this, SLOT(respond(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::respond(int value)
{
    qDebug() << "Value: " << value;
}

