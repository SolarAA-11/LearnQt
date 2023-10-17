#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->waterTank, &WaterTank::normal,
            ui->indicator, &Indicator::setLightGreen);
    connect(ui->waterTank, &WaterTank::warning,
            ui->indicator, &Indicator::setLightYellow);
    connect(ui->waterTank, &WaterTank::danger,
            ui->indicator, &Indicator::setLightRed);
}

Widget::~Widget()
{
    delete ui;
}

