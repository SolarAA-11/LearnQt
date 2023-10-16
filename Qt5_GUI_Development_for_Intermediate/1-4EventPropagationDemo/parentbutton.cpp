#include "parentbutton.h"

ParentButton::ParentButton(QWidget *parent)
    : QPushButton(parent)
{

}




void ParentButton::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Parent Mouse Event";
    QPushButton::mousePressEvent(event);
}
