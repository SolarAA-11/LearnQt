#include "indicator.h"

#include <QPalette>

Indicator::Indicator(QWidget *parent)
    : QWidget{parent}
    , m_light_state(LightState::Green)
    , m_light_on(true)
{
    // Timer
    m_timer = new QTimer(this);
    m_timer->setInterval(500);
    connect(m_timer, &QTimer::timeout, this, &Indicator::onTimeOut);
    m_timer->start();

    // Set Background Color
    QPalette pal = QWidget::palette();
    pal.setColor(QPalette::Window, Qt::gray);
    setPalette(pal);
    setAutoFillBackground(true);
}

void Indicator::onTimeOut()
{
    m_light_on = !m_light_on;
    update();
}

void Indicator::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::black);

    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::black);
    painter.setPen(pen);

    size_t widgetWidth = width();
    size_t widgetHeight = height();
    size_t spacing = 3;
    size_t margin = 6;

    size_t circleDiameter = (widgetHeight - 2 * spacing - 2 * margin) / 3;

    QRect circleRect(
        QPoint(margin, margin),
        QSize(circleDiameter, circleDiameter));
    QList<QRect> circleRectList;
    circleRectList << circleRect
                   << circleRect.translated(0, circleDiameter + spacing)
                   << circleRect.translated(0, (circleDiameter + spacing) * 2);
    for(int i = 0; i < 3; ++i)
    {
        painter.drawEllipse(circleRectList[i]);
    }

    size_t circleIndex;
    QColor circleColor;

    switch (m_light_state) {
    case LightState::Green:
        circleIndex = 0;
        circleColor = Qt::green;
        break;
    case LightState::Yellow:
        circleIndex = 1;
        circleColor = Qt::yellow;
        break;
    case LightState::Red:
        circleIndex = 2;
        circleColor = Qt::red;
        break;
    default:
        break;
    }

    if(m_light_on)
    {
        painter.setBrush(circleColor);
        painter.drawEllipse(circleRectList[circleIndex]);
    }
}
