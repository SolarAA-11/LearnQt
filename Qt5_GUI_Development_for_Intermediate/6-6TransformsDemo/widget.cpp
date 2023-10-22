#include "widget.h"
#include "./ui_widget.h"

#include <QGraphicsRectItem>
#include <QGraphicsLineItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(m_scene);

    m_scene->addLine(-300,0,300,0);
    m_scene->addLine(0,-300,0,300);

    // Add Three Rect Item to Scene
    auto funcToAddRect = [=](const QRect &rect, const QColor &color) -> QGraphicsRectItem*  {
        QGraphicsRectItem *item = new QGraphicsRectItem();
        item->setRect(rect);
        item->setBrush(color);
        item->setFlag(QGraphicsItem::ItemIsSelectable);
        m_scene->addItem(item);
        return item;
    };
    funcToAddRect(
        QRect(0,0,300,100),
        Qt::red);

    auto greenItem = funcToAddRect(
        QRect(0,0,300,100),
        Qt::green);

    QTransform itemTransform = greenItem->transform();
    itemTransform.rotate(45);
    greenItem->setTransform(itemTransform);

    funcToAddRect(
        QRect(0,0,50,50),
        Qt::blue);

    connect(m_scene, &QGraphicsScene::selectionChanged, [=](){
        auto selectedItemList = m_scene->selectedItems();
        if(!selectedItemList.empty())
        {
            auto item = selectedItemList.first();
            qDebug() << "Selected Changed";
            qDebug() << item->transform();

            QTransform itemTransform = item->transform();
            ui->xTranslateSpinBox->blockSignals(true);
            ui->yTranslateSpinBox->blockSignals(true);
            ui->xScaleSpinBox->blockSignals(true);
            ui->yScaleSpinBox->blockSignals(true);
            ui->xShearSpinBox->blockSignals(true);
            ui->yShearSpinBox->blockSignals(true);

            ui->xTranslateSpinBox->setValue(itemTransform.m31());
            ui->yTranslateSpinBox->setValue(itemTransform.m32());

            ui->xScaleSpinBox->setValue(itemTransform.m11());
            ui->yScaleSpinBox->setValue(itemTransform.m22());

            ui->xShearSpinBox->setValue(itemTransform.m21());
            ui->yShearSpinBox->setValue(itemTransform.m12());

            ui->xTranslateSpinBox->blockSignals(false);
            ui->yTranslateSpinBox->blockSignals(false);
            ui->xScaleSpinBox->blockSignals(false);
            ui->yScaleSpinBox->blockSignals(false);
            ui->xShearSpinBox->blockSignals(false);
            ui->yShearSpinBox->blockSignals(false);
        }
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_xTranslateSpinBox_valueChanged(int arg1)
{
    auto selectedItem = getSelectedItem();
    if(selectedItem != nullptr)
    {
        auto itemTransform = selectedItem->transform();
        itemTransform.translate(arg1 - itemTransform.dx(),0);
        selectedItem->setTransform(itemTransform);
    }
}

void Widget::on_yTranslateSpinBox_valueChanged(int arg1)
{
    auto selectedItem = getSelectedItem();
    if(selectedItem != nullptr)
    {
        auto itemTransform = selectedItem->transform();
        itemTransform.translate(0,arg1 - itemTransform.dy());
        selectedItem->setTransform(itemTransform);
    }
}


void Widget::on_xScaleSpinBox_valueChanged(int arg1)
{
    auto selectedItem = getSelectedItem();
    if(selectedItem != nullptr)
    {
        auto itemTransform = selectedItem->transform();
        double scaleFactor = arg1/itemTransform.m11();
        itemTransform.scale(scaleFactor,1);
        selectedItem->setTransform(itemTransform);
    }
}


void Widget::on_yScaleSpinBox_valueChanged(int arg1)
{
    auto selectedItem = getSelectedItem();
    if(selectedItem != nullptr)
    {
        auto itemTransform = selectedItem->transform();
        double scaleFactor = arg1/itemTransform.m22();
        itemTransform.scale(1, scaleFactor);
        selectedItem->setTransform(itemTransform);
    }
}


void Widget::on_xShearSpinBox_valueChanged(int arg1)
{
    auto selectedItem = getSelectedItem();
    if(selectedItem != nullptr)
    {
        auto itemTransform = selectedItem->transform();
        itemTransform.shear(arg1 - itemTransform.m21(), 0);
        selectedItem->setTransform(itemTransform);
    }
}


void Widget::on_yShearSpinBox_valueChanged(int arg1)
{
    auto selectedItem = getSelectedItem();
    if(selectedItem != nullptr)
    {
        auto itemTransform = selectedItem->transform();
        itemTransform.shear(0, arg1 - itemTransform.m12());
        selectedItem->setTransform(itemTransform);
    }
}


void Widget::on_rotationSpinBox_valueChanged(int arg1)
{
    auto selectedItem = getSelectedItem();
    if(selectedItem != nullptr)
    {
        auto itemTransform = selectedItem->transform();
        itemTransform.rotate(arg1);
        selectedItem->setTransform(itemTransform);
    }
}


QGraphicsItem *Widget::getSelectedItem() const
{
    auto selectedItemList = m_scene->selectedItems();
    if(!selectedItemList.empty())
    {
        return selectedItemList.first();
    } else return nullptr;
}

