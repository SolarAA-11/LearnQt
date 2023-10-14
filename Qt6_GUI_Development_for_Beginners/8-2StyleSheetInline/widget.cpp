#include "widget.h"
#include "./ui_widget.h"

#include "somedialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    SomeDialog *dialog = new SomeDialog(this);
    dialog->setStyleSheet("QPushButton{background-color: yellow; color: red;}");
    dialog->show();
}

