#include "childbutton.h"

ChildButton::ChildButton(QWidget *parent)
    : ParentButton(parent)
{

}


void ChildButton::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Child Event";
}
