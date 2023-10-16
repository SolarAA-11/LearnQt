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
        qDebug() << "Hijacked mouse event";
        return true;
    }

    return QObject::eventFilter(watched, event);
}
