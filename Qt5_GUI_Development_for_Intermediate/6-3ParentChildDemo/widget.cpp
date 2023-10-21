#include "widget.h"
#include "./ui_widget.h"

#include <QGraphicsPixmapItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(m_scene);

    m_parentRect = new QGraphicsRectItem();
    QPen pen;
    pen.setWidth(4);
    m_parentRect->setPen(pen);
    m_parentRect->setBrush(Qt::blue);
    m_parentRect->setRect(0,0,100,100);
    m_parentRect->setFlag(QGraphicsItem::ItemIsMovable);
    m_scene->addItem(m_parentRect);

    QGraphicsRectItem *childRect = new QGraphicsRectItem(m_parentRect);
    childRect->setPen(pen);
    childRect->setBrush(Qt::yellow);
    childRect->setRect(0,0,50,50);

    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(m_parentRect);
    pixmapItem->setPixmap(QPixmap(":/images/Quick.png"));
    pixmapItem->setPos(50,50);
}


Widget::~Widget()
{
    delete ui;
}


void Widget::on_showHideButton_clicked()
{
    if(m_parentRect != nullptr)
        m_parentRect->setVisible(!m_parentRect->isVisible());
}


void Widget::on_removeButton_clicked()
{
    if(m_parentRect != nullptr)
    {
        delete m_parentRect;
        m_parentRect = nullptr;
    }
}

