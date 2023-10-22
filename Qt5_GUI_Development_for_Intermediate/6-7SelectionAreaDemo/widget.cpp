#include "widget.h"
#include "./ui_widget.h"

#include <QGraphicsRectItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene();
    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setIsDrawForeground(ui->showGridCheckBox->isChecked());
    ui->graphicsView->setSceneRect(-800,-400,1600,800);

    m_item1 = m_scene->addRect(
        QRect(10,10,100,100),
        QPen(),
        Qt::blue);
    m_item1->setFlag(QGraphicsItem::ItemIsSelectable);

    m_item2 = m_scene->addRect(
        QRect(30,30,130,130),
        QPen(),
        Qt::yellow);
    m_item2->setFlag(QGraphicsItem::ItemIsSelectable);

    m_item3 = m_scene->addEllipse(-850,-50,500,500);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_centerViewButton_clicked()
{
    ui->graphicsView->centerOn(QPointF());
}


void Widget::on_showGridCheckBox_toggled(bool checked)
{
    ui->graphicsView->setIsDrawForeground(checked);
}


void Widget::on_fitInViewButton_clicked()
{
    ui->graphicsView->fitInView(m_item3);
}


void Widget::on_zoomInButton_clicked()
{
    ui->graphicsView->scale(1.1,1.1);
}


void Widget::on_zoomOutButton_clicked()
{
    ui->graphicsView->scale(1/1.1,1/1.1);
}


void Widget::on_resetButton_clicked()
{
    ui->graphicsView->resetTransform();
}


void Widget::on_ensureVisibleButton_clicked()
{
    ui->graphicsView->ensureVisible(m_item3);
}

