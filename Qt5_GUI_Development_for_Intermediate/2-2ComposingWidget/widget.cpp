#include "widget.h"
#include "./ui_widget.h"

#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_colorpicker = new ColorPicker(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_colorpicker);
    setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

