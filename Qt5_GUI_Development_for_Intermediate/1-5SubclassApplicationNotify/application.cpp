#include "application.h"
#include "widget.h"

#include <QEvent>

Application::Application(int argc, char **argv)
    : QApplication(argc, argv)
{

}

bool Application::notify(QObject *receiver, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress
        ||event->type() == QEvent::MouseButtonDblClick)
    {
        qDebug() << "Application: Mouse press or double click detected";
        qDebug() << "Class Name: " << receiver->metaObject()->className();

        Widget *button = dynamic_cast<Widget*>(receiver);
        if(button != nullptr)
        {
            qDebug() << "Deliver Successful";
        } else
        {
            qDebug() << "Deliver Failed";
        }

        return false;
    }
    return QApplication::notify(receiver, event);
}
