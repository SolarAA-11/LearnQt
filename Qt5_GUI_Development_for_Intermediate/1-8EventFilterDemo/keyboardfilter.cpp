#include "keyboardfilter.h"

#include <QEvent>
#include <QKeyEvent>
#include <QDebug>

KeyboardFilter::KeyboardFilter(QObject *parent)
    : QObject{parent}
{

}


bool KeyboardFilter::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if(keyEvent->key() >= static_cast<int>('0') &&
            keyEvent->key() <= static_cast<int>('9'))
        {
            qDebug() << "Filter Number Out";
            return true;
        } else return false;
    }

    return QObject::eventFilter(watched, event);
}
