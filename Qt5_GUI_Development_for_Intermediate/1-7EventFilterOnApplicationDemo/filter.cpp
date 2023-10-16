#include "filter.h"

#include <QEvent>
#include <QDebug>

Filter::Filter(QObject *parent)
    : QObject{parent}
{

}


bool Filter::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress
        || event->type() == QEvent::MouseButtonDblClick)
    {
        qDebug() << "Mouse Event Hijacked";
        return true;
    }

    return QObject::eventFilter(watched, event);
}
