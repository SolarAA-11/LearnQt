#include "widget.h"
#include "./ui_widget.h"

#include <QPen>
#include <QPainter>
#include <QPainterPath>

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



void Widget::paintEvent(QPaintEvent *event)
{
    QPainterPath painterPath;

    // add a rect
//    painterPath.addRect(100, 100, 100, 100);

    // Use QRect object
    QRect rect(
        QPoint(100.0, 100.0),
        QPoint(200.0, 200.0));
    painterPath.addRect(rect);

    // Draw a one of quarter circlr
    painterPath.moveTo(QPoint(150, 150));
    painterPath.lineTo(QPoint(150, 50));
    painterPath.arcTo(
        QRect(50, 50, 200, 200),
        90, 90);
    painterPath.lineTo(QPoint(150, 150));

    // two circles linked with two lines
    QPainterPath painterPath2;
    painterPath2.addEllipse(100, 250, 100, 100);
    painterPath2.addEllipse(400, 250, 100, 100);
    painterPath2.moveTo(150, 250);
    painterPath2.lineTo(450, 250);
    painterPath2.moveTo(150, 350);
    painterPath2.lineTo(450, 350);


    QPen pen;
    pen.setWidth(1);

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(Qt::green);

    painter.drawPath(painterPath);
    painter.drawPath(painterPath2);

    painterPath2.translate(100, 200);
    painter.drawPath(painterPath2);
}
