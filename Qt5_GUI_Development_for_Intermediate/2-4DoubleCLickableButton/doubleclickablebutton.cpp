#include "doubleclickablebutton.h"

DoubleClickableButton::DoubleClickableButton(QWidget *parent)
    : QWidget{parent}
{

}


void DoubleClickableButton::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit doubleClicked();
    QWidget::mouseDoubleClickEvent(event);
}
