#include "watertank.h"

#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QPoint>
#include <QList>
#include <QLine>
#include <QWheelEvent>

WaterTank::WaterTank(QWidget *parent)
    : QWidget{parent}
    , m_timer(new QTimer)
    , m_water_height_percent(0)
{
    m_timer->setInterval(500);
    m_timer->start();
    connect(m_timer, &QTimer::timeout, this, &WaterTank::onTimeOut);
}


void WaterTank::paintEvent(QPaintEvent *event)
{
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(3);

    QPainter painter(this);
    painter.setPen(pen);

    drawContainer(painter);
    drawWaterArea(painter);
}


void WaterTank::wheelEvent(QWheelEvent *event)
{
    if(event->angleDelta().y() < 0)
    {
        m_water_height_percent -= 0.01;
        update();
    }
}

void WaterTank::onTimeOut()
{
    m_water_height_percent += 0.05;
    update();
}

void WaterTank::drawContainer(QPainter &painter)
{
    int widgeWidth = width();
    int widgetHeigth = height();

    int marginWidth = 3;

    QPoint topLeftCorner(marginWidth, marginWidth);
    QPoint bottomRightCorner(
        widgeWidth - marginWidth,
        widgetHeigth - marginWidth);
    QPoint bottomLeftCorner(topLeftCorner.x(), bottomRightCorner.y());
    QPoint topRightCorner(bottomRightCorner.x(), topLeftCorner.y());

    QList<QLine> lines;
    lines << QLine(topLeftCorner, bottomLeftCorner)
          << QLine(bottomLeftCorner, bottomRightCorner)
          << QLine(bottomRightCorner, topRightCorner);

    painter.drawLines(lines);
}

void WaterTank::drawWaterArea(QPainter &painter)
{
    int widgeWidth = width();
    int widgetHeigth = height();

    int marginWidth = 3;
    int waterHeight = (widgetHeigth - marginWidth - painter.pen().width()) * m_water_height_percent;

    int penWidth = painter.pen().width();

    QPoint topLeftCorner(
        marginWidth + 1,
        widgetHeigth - marginWidth - painter.pen().width() - waterHeight);
    QPoint bottomRightCorner(
        widgeWidth - marginWidth - painter.pen().width(),
        widgetHeigth - marginWidth - painter.pen().width());

    painter.setBrush(Qt::blue);
    QPen pen;
    pen.setWidth(0);
    painter.setPen(pen);
    painter.drawRect(QRect(topLeftCorner, bottomRightCorner));
}
