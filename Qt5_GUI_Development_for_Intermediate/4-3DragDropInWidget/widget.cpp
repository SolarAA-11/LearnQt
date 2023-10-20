#include "widget.h"
#include "./ui_widget.h"

#include "container.h"

#include <QSplitter>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QSplitter *splitter = new QSplitter(this);

    Container *container1 = new Container(this);
    Container *container2 = new Container(this);
    splitter->addWidget(container1);
    splitter->addWidget(container2);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(splitter);
    setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

