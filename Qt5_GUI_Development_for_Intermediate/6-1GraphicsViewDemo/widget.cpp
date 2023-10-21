#include "widget.h"
#include "./ui_widget.h"

#include "myrect.h"

#include <QGraphicsRectItem>
#include <QGraphicsLineItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene(this);

    /// Add Rect
    /// There are two ways
    /// 1. QGraphicsScene::addRect
    /// 2. Create a new QGraphicsRectItem

//    auto item = m_scene->addRect(10, 10, 100, 100);

//    QPen pen;
//    pen.setWidth(4);
//    pen.setColor(Qt::red);
//    item->setPen(pen);

//    item->setBrush(Qt::green);

    QGraphicsRectItem *item = new QGraphicsRectItem();
    item->setRect(10, 10, 100, 100);

    QPen pen;
    pen.setWidth(4);
    pen.setColor(Qt::red);
    item->setPen(pen);

    item->setBrush(Qt::green);
    item->setFlag(QGraphicsItem::ItemIsMovable);

    m_scene->addItem(item);

    // Add my own rect item
    MyRect *rectItem = new MyRect();
    rectItem->setRect(10, -110, 100, 100);
    rectItem->setPen(pen);
    rectItem->setBrush(Qt::blue);
    rectItem->setFlag(QGraphicsItem::ItemIsFocusable);
    rectItem->setFocus(Qt::MouseFocusReason);
    m_scene->addItem(rectItem);

    // Draw lines
    m_scene->addLine(-300, 0, 300, 0);
    m_scene->addLine(0, -300, 0, 300);

    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setBackgroundBrush(Qt::yellow);
}

Widget::~Widget()
{
    delete ui;
}

