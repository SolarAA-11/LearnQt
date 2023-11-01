#include "widget.h"
#include "ui_widget.h"

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


void Widget::on_horizontalSlider_4_valueChanged(int value)
{
    QString newLabelValue = QString("Value changes to %1").arg(value);
    ui->valueChangedLabel->setText(newLabelValue);
}


void Widget::on_horizontalSlider_4_sliderPressed()
{
    ui->sliderPressedLabel->setText("Slider Pressed");
    ui->sliderMovedLabel->clear();
    ui->sliderReleasedLabel->clear();
}


void Widget::on_horizontalSlider_4_sliderMoved(int position)
{
    ui->sliderMovedLabel->setText("Slider Moved");
}


void Widget::on_horizontalSlider_4_sliderReleased()
{
    ui->sliderPressedLabel->clear();
    ui->sliderMovedLabel->clear();
    ui->sliderReleasedLabel->setText("Slider Released");
}

