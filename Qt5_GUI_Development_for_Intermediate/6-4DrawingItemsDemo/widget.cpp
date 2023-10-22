#include "widget.h"
#include "./ui_widget.h"

#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsPathItem>
#include <QGraphicsPixmapItem>
#include <QPainterPath>
#include <QPolygon>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene(this);
    m_scene->setSceneRect(-400, -400, 800, 800);
    m_scene->addLine(-400,0,400,0);
    m_scene->addLine(0,-400,0,400);

    ui->graphicsView->setScene(m_scene);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_lineButton_clicked()
{
    QLineF line(10,10,80,80);
    QGraphicsLineItem *lineItem = new QGraphicsLineItem(line);
    lineItem->setPen(QPen(Qt::green, 4));

    QGraphicsRectItem *rectItem = new QGraphicsRectItem();
    rectItem->setRect(lineItem->boundingRect().adjusted(-10,-10,10,10));
    rectItem->setFlag(QGraphicsItem::ItemIsMovable);
    lineItem->setParentItem(rectItem);

    m_scene->addItem(rectItem);
}


void Widget::on_ellipseButton_clicked()
{
    QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem();
    ellipseItem->setRect(-90, -90, 80, 80);
    ellipseItem->setPen(QPen(Qt::red, 4));
    ellipseItem->setBrush(Qt::green);

    QGraphicsRectItem *rectItem = new QGraphicsRectItem();
    rectItem->setRect(ellipseItem->boundingRect().adjusted(-10,-10,10,10));
    rectItem->setFlag(QGraphicsItem::ItemIsMovable);
    ellipseItem->setParentItem(rectItem);

    m_scene->addItem(rectItem);
}


void Widget::on_pathButton_clicked()
{
    QPainterPath painterPath;
    painterPath.addRect(30,30,30,30);
    painterPath.addEllipse(20,20,40,40);

    QGraphicsPathItem *pathItem = new QGraphicsPathItem(painterPath);
    pathItem->setBrush(Qt::blue);

    QGraphicsRectItem *rectItem = new QGraphicsRectItem();
    rectItem->setRect(pathItem->boundingRect().adjusted(-10,-10,10,10));
    rectItem->setFlag(QGraphicsItem::ItemIsMovable);
    pathItem->setParentItem(rectItem);

    m_scene->addItem(rectItem);
}


void Widget::on_pieButton_clicked()
{
    QPainterPath painterPath(QPointF(80,80));
    painterPath.arcTo(
        QRect(10,10,140,140),
        30, 120);
    painterPath.lineTo(QPointF(80,80));

    QGraphicsPathItem *pathItem = new QGraphicsPathItem(painterPath);
    pathItem->setBrush(Qt::red);

    QGraphicsRectItem *rectItem = new QGraphicsRectItem();
    rectItem->setRect(pathItem->boundingRect().adjusted(-10,-10,10,10));
    rectItem->setFlag(QGraphicsItem::ItemIsMovable);
    pathItem->setParentItem(rectItem);

    m_scene->addItem(rectItem);
}


void Widget::on_imageButton_clicked()
{
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem();
    QPixmap pixmap(":/images/qt.png");
    pixmapItem->setPixmap(pixmap.scaled(110, 110));

    QGraphicsRectItem *rectItem = new QGraphicsRectItem();
    rectItem->setRect(pixmapItem->boundingRect().adjusted(-10,-10,10,10));
    rectItem->setFlag(QGraphicsItem::ItemIsMovable);
    pixmapItem->setParentItem(rectItem);

    m_scene->addItem(rectItem);
}


void Widget::on_starButton_clicked()
{
    QPolygon polygon;
    polygon << QPoint(0, 85) << QPoint(75, 75)
         << QPoint(100, 10) << QPoint(125, 75)
         << QPoint(200, 85) << QPoint(150, 125)
         << QPoint(160, 190) << QPoint(100, 150)
         << QPoint(40, 190) << QPoint(50, 125)
         << QPoint(0, 85);

    QPainterPath painterPath;
    painterPath.addPolygon(polygon);

    QGraphicsPathItem *pathItem = new QGraphicsPathItem();
    pathItem->setPath(painterPath);
    pathItem->setBrush(Qt::blue);

    QGraphicsRectItem *rectItem = new QGraphicsRectItem();
    rectItem->setRect(pathItem->boundingRect().adjusted(-10,-10,10,10));
    rectItem->setFlag(QGraphicsItem::ItemIsMovable);
    pathItem->setParentItem(rectItem);

    m_scene->addItem(rectItem);
}

