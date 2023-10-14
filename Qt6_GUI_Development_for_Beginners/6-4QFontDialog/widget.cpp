#include "widget.h"
#include "./ui_widget.h"

#include <QFontDialog>

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


void Widget::on_chooseFontButton_clicked()
{
    bool ok = false;
    QFont font = QFontDialog::getFont(
        &ok,
        ui->label->font(),
        this);
    if(ok) {
        ui->label->setFont(font);
    } else {

    }
}

