#include "myview.h"

#include <QMouseEvent>
#include <QGraphicsRectItem>

MyView::MyView(QWidget *parent)
    : QGraphicsView(parent)
{

}


void MyView::mousePressEvent(QMouseEvent *event)
{
    if(scene() != nullptr)
    {
        QPoint viewPosition = event->pos();
        QPoint scenePosition = mapToScene(viewPosition).toPoint();
        qDebug() << "Mouse clicked at: " << viewPosition << " in view";
        qDebug() << "----- clicked at: " << scenePosition << " in scene";

        QGraphicsRectItem *rect = scene()->addRect(scenePosition.x(), scenePosition.y(), 50, 50);
        rect->setBrush(Qt::blue);
    }

}
