#include "widget.h"
#include "ui_widget.h"

#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Set label content
    ui->plainTextLabel->setText("Plain Text");
    ui->richTextLabel->setText("<h1>Rich Text</h1>");

    // Set Pixmap
    QPixmap pixmap("://resource/a.png");
    ui->pixmapLabel->setPixmap(pixmap);

    ui->numberLabel->setNum(12);


    // Label Alignment
    ui->baselineLabel->setAlignment(Qt::AlignBaseline);
}

Widget::~Widget()
{
    delete ui;
}

