#include "widget.h"
#include "./ui_widget.h"

#include <QPainter>
#include <QPen>
#include <QLinearGradient>
#include <QRadialGradient>
#include <QConicalGradient>

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
    QPainter painter(this);
    QPen pen;
    pen.setWidth(4);
    pen.setColor(Qt::green);

    // LinearGradient
    QLinearGradient linearGradient(
        QPointF(10.0, 50.0),
        QPointF(10.0, 100.0));
    linearGradient.setColorAt(0.0, Qt::green);
    linearGradient.setColorAt(1.0, Qt::yellow);

    QRect rect(QPoint(10.0, 10.0), QPoint(100.0, 200.0));

    // Spread
    linearGradient.setSpread(QGradient::PadSpread);
    painter.setBrush(linearGradient);
    painter.drawRect(rect);

    // Reflect
    linearGradient.setSpread(QGradient::ReflectSpread);
    painter.setBrush(linearGradient);
    rect.translate(110, 0);
    painter.drawRect(rect);

    // Repeat
    linearGradient.setSpread(QGradient::RepeatSpread);
    painter.setBrush(linearGradient);
    rect.translate(110, 0);
    painter.drawRect(rect);

    // RadialGradient
    QRadialGradient radialGradient(50, 250, 30);
    radialGradient.setColorAt(0.0, Qt::green);
    radialGradient.setColorAt(1.0, Qt::yellow);

    rect = QRect(
        QPoint(10, 210),
        QPoint(100, 410));

    // PadSpread
    radialGradient.setSpread(QGradient::PadSpread);
    painter.setBrush(radialGradient);
    painter.drawRect(rect);

    // ReflectSpread
    radialGradient = QRadialGradient(160, 250, 30);
    radialGradient.setColorAt(0.0, Qt::green);
    radialGradient.setColorAt(1.0, Qt::yellow);
    radialGradient.setSpread(QGradient::ReflectSpread);
    rect.translate(110, 0);
    painter.setBrush(radialGradient);
    painter.drawRect(rect);

    // RepeatSpread
    radialGradient = QRadialGradient(270, 250, 30);
    radialGradient.setColorAt(0.0, Qt::green);
    radialGradient.setColorAt(1.0, Qt::yellow);
    radialGradient.setSpread(QGradient::RepeatSpread);
    rect.translate(110, 0);
    painter.setBrush(radialGradient);
    painter.drawRect(rect);

    // QConicalGradient
    QConicalGradient conicalGradient(50, 500, 0);
    conicalGradient.setColorAt(0.0, Qt::green);
    conicalGradient.setColorAt(1.0, Qt::yellow);

    rect = QRect(
        QPoint(10, 470),
        QPoint(100, 520));

    painter.setBrush(conicalGradient);
    painter.drawRect(rect);
}
