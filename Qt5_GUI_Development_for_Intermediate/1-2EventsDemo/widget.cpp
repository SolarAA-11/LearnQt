#include "widget.h"
#include "./ui_widget.h"

#include <QMouseEvent>
#include <QCloseEvent>
#include <QContextMenuEvent>
#include <QKeyEvent>
#include <QResizeEvent>
#include <QPaintEvent>
#include <QMenu>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Pressed";
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Released";
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "Move: " << event->pos();
}


void Widget::closeEvent(QCloseEvent *event)
{
    qDebug() << "Widget is about to close";
//    event->ignore();
}


void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug() << "Context Menu Event";

    QMenu *menuWidget = new QMenu(this);
    menuWidget->addAction(tr("Action 1"));
    menuWidget->addAction(tr("Action 2"));

    menuWidget->popup(mapToGlobal(event->pos()));
}


void Widget::enterEvent(QEnterEvent *event)
{
    qDebug() << "Mouse Enter";
}

void Widget::leaveEvent(QEvent *event)
{
    qDebug() << "Mouse Leave";
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key Pressed: " << event->key() << " : " << event->text();

    if(event->modifiers() & Qt::ShiftModifier) {
        qDebug() << "Shift";
    } else if (event->modifiers() & Qt::ControlModifier) {
        qDebug() << "Control";
    } else if (event->modifiers() & Qt::AltModifier) {
        qDebug() << "Alt";
    }
}

void Widget::wheelEvent(QWheelEvent *event)
{

}

void Widget::paintEvent(QPaintEvent *event)
{
    qDebug() << "Paint Event";
}

void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << "Resize Event: "
             << "Old Size: " << event->oldSize()
             << " , New Size: " << event->size();
}
