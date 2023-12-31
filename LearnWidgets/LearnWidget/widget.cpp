#include "widget.h"
#include "ui_widget.h"

#include <QPixmap>
#include <QIcon>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("Hello World");

    QPixmap pixmap("://images/a.png");
    setWindowIcon(QIcon(pixmap));
}

Widget::~Widget()
{
    delete ui;
}

