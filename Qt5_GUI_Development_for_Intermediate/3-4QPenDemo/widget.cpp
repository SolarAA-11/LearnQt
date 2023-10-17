#include "widget.h"
#include "./ui_widget.h"

#include <QPainter>
#include <QPen>

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
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(4);

    // Set Painter and Brush, then draw a Rectangle
    QPainter painter(this);
    painter.setBrush(Qt::red);

    // SolidLine Style
    painter.setPen(pen);
    painter.drawRect(QRect(10, 10, 50, 50));

    // NoPen Style
    pen.setStyle(Qt::NoPen);
    painter.setPen(pen);
    painter.drawRect(QRect(70, 10, 50, 50));

    // DashLine
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);
    painter.drawRect(QRect(130, 10, 50, 50));

    // DotLine
    pen.setStyle(Qt::DotLine);
    painter.setPen(pen);
    painter.drawRect(QRect(190, 10, 50, 50));

    // DashDotLine
    pen.setStyle(Qt::DashDotLine);
    painter.setPen(pen);
    painter.drawRect(QRect(250, 10, 50, 50));

    // Custom Dash Line
    QVector<qreal> dashes;
    qreal space = 4;
    dashes << 1 << space << 3 << space << 9 << space
           << 27 << space << 9 << space;
    pen.setDashPattern(dashes);
    painter.setPen(pen);
    painter.drawRect(310, 10, 50, 50);

    // Line Cap Style
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(16);

    // FlatCap
    pen.setCapStyle(Qt::FlatCap);
    QLine line(
        QPoint(30, 100),
        QPoint(330, 100));
    painter.setPen(pen);
    painter.drawLine(line);

    // SquareCap
    pen.setCapStyle(Qt::SquareCap);
    line.translate(0, 30);
    painter.setPen(pen);
    painter.drawLine(line);

    // RoundCap
    pen.setCapStyle(Qt::RoundCap);
    line.translate(0, 30);
    painter.setPen(pen);
    painter.drawLine(line);
}
