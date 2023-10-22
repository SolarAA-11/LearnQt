#include "view.h"

#include <QMouseEvent>
#include <QGraphicsItem>

const double GRID_VERTICAL_LINE_SPACING = 40;
const double GRID_HORIZONTAL_LINE_SPACING = 40;

View::View(QWidget *parent)
    : QGraphicsView(parent)
    , m_isDrawForeground(true)
    , m_selectAreaLeftTop(std::nullopt)
    , m_polygonSelectAreaItem(nullptr)
{

}


void View::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->save();

    painter->setBrush(QBrush(Qt::yellow));

    painter->drawRect(-800,-400,1600,800);

    painter->restore();
}


void View::drawForeground(QPainter *painter, const QRectF &rect)
{
    if(m_isDrawForeground)
    {
        painter->save();

        // Draw grid lines
        // Vertical Lines
        QList<QLineF> lineList;
        double verticalLineX = 0;
        while(verticalLineX > rect.x())
        {
            lineList << QLineF(verticalLineX, rect.y(), verticalLineX, rect.y() + rect.height());
            verticalLineX -= GRID_VERTICAL_LINE_SPACING;
        }
        verticalLineX = 0;
        while(verticalLineX < rect.x() + rect.width())
        {
            lineList << QLineF(verticalLineX, rect.y(), verticalLineX, rect.y() + rect.height());
            verticalLineX += GRID_VERTICAL_LINE_SPACING;
        }

        // Horizontal Lines
        double horizontalLineY = 0;
        while(horizontalLineY > rect.y())
        {
            lineList << QLineF(rect.x(), horizontalLineY, rect.x() + rect.width(), horizontalLineY);
            horizontalLineY -= GRID_HORIZONTAL_LINE_SPACING;
        }
        horizontalLineY = 0;
        while(horizontalLineY < rect.y() + rect.height())
        {
            lineList << QLineF(rect.x(), horizontalLineY, rect.x() + rect.width(), horizontalLineY);
            horizontalLineY += GRID_HORIZONTAL_LINE_SPACING;
        }

        // Draw Lines
        painter->setPen(QPen(Qt::red, 1));
        painter->drawLines(lineList);

        painter->restore();
    } else
    {
        QGraphicsView::drawForeground(painter, rect);
    }
}

bool View::isDrawForeground() const
{
    return m_isDrawForeground;
}

void View::setIsDrawForeground(bool newIsDrawForeground)
{
    if(m_isDrawForeground != newIsDrawForeground)
    {
        m_isDrawForeground = newIsDrawForeground;
        scene()->update();
    }
}


void View::mousePressEvent(QMouseEvent *event)
{
    QPointF pressPos = event->pos();
    QGraphicsItem *pressedItem = scene()->itemAt(
        mapToScene(pressPos.toPoint()),
        transform());

    if(pressedItem == nullptr)
    {
        m_selectAreaLeftTop = pressPos;
    }
    QGraphicsView::mousePressEvent(event);
}

void View::mouseReleaseEvent(QMouseEvent *event)
{
    if(m_selectAreaLeftTop.has_value())
    {
        if(m_polygonSelectAreaItem != nullptr)
        {
            scene()->removeItem(m_polygonSelectAreaItem);
            delete m_polygonSelectAreaItem;
            m_polygonSelectAreaItem = nullptr;
        }

        m_selectAreaLeftTop = std::nullopt;

        scene()->update();
    }
    QGraphicsView::mouseReleaseEvent(event);
}

void View::mouseMoveEvent(QMouseEvent *event)
{
    if(m_selectAreaLeftTop.has_value())
    {
        const QPointF& leftTop = m_selectAreaLeftTop.value();
        QPointF currentPos = event->pos();
        QRectF selectedRectFromView(leftTop,currentPos);
        QPolygonF selectedRectFromScene = mapToScene(selectedRectFromView.toRect());

        QPainterPath painterPath;
        painterPath.addPolygon(selectedRectFromScene);
        scene()->setSelectionArea(painterPath);

        if(m_polygonSelectAreaItem != nullptr)
        {
            scene()->removeItem(m_polygonSelectAreaItem);
            delete m_polygonSelectAreaItem;
            m_polygonSelectAreaItem = nullptr;
        }

        m_polygonSelectAreaItem = new QGraphicsPolygonItem();
        m_polygonSelectAreaItem->setPolygon(selectedRectFromScene);
        m_polygonSelectAreaItem->setPen(QPen(Qt::black, 2, Qt::DashDotLine));
        m_polygonSelectAreaItem->setBrush(QColor(250,0,0,50));

        scene()->addItem(m_polygonSelectAreaItem);

        scene()->update();
    }
    QGraphicsView::mouseMoveEvent(event);
}
