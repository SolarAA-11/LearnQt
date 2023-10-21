#include "myrect.h"

#include <QKeyEvent>

MyRect::MyRect()
{

}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key pressed";
    auto key = event->key();
    if(key == Qt::Key_Left)
    {
        moveBy(-20, 0);
    } else if(key == Qt::Key_Right)
    {
        moveBy(20, 0);
    } else if(key == Qt::Key_Down)
    {
        moveBy(0, 20);
    } else if(key == Qt::Key_Up)
    {
        moveBy(0, -20);
    }
}
