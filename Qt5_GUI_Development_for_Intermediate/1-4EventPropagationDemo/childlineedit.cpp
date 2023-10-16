#include "childlineedit.h"

#include <QKeyEvent>

ChildLineEdit::ChildLineEdit(QWidget *parent)
    : ParentLineEdit(parent)
{

}


void ChildLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Child Line Edit Key Press Event";
    if(event->key() == Qt::Key_Delete)
    {
        clear();
        event->accept();
    } else
    {

        event->ignore();
    }
}
