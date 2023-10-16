#include "button.h"

#include <QEvent>
#include <QDebug>

Button::Button(QWidget *parent)
{

}


bool Button::event(QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress
        || event->type() == QEvent::MouseButtonDblClick)
    {
        // This implementation doesn't call the parent class's event method
        // which causes this widget can not behave normally
        // For example, widget can't emit clicked signal
        qDebug() << "Button click or double click";
        return true;
    }

    return QPushButton::event(event);
}
