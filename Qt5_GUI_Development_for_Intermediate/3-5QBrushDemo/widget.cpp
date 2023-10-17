#include "widget.h"
#include "./ui_widget.h"

#include <QPainter>
#include <QBrush>

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


void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    brush.setColor(Qt::red);

    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::green);
    painter.setPen(pen);
    QRect rect(10, 10, 100, 100);

    // Solid Pattern
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(rect);

    // Dense 1 Pattern
    rect.translate(110, 0);
    brush.setStyle(Qt::Dense1Pattern);
    painter.setBrush(brush);
    painter.drawRect(rect);

    // Dense 2 Pattern
    rect.translate(110, 0);
    brush.setStyle(Qt::Dense2Pattern);
    painter.setBrush(brush);
    painter.drawRect(rect);

    // Dense 3 Pattern
    rect.translate(110, 0);
    brush.setStyle(Qt::Dense3Pattern);
    painter.setBrush(brush);
    painter.drawRect(rect);

    // Dense 4 Pattern
    rect.translate(110, 0);
    brush.setStyle(Qt::Dense4Pattern);
    painter.setBrush(brush);
    painter.drawRect(rect);

    // Dense 5 Pattern
    rect.translate(110, 0);
    brush.setStyle(Qt::Dense5Pattern);
    painter.setBrush(brush);
    painter.drawRect(rect);

    // Dense 6 Pattern
    rect.setRect(10, 120, 100, 100);
    brush.setStyle(Qt::Dense6Pattern);
    painter.setBrush(brush);
    painter.drawRect(rect);

    // Dense 7 Pattern
    rect.translate(110, 0);
    brush.setStyle(Qt::Dense7Pattern);
    painter.setBrush(brush);
    painter.drawRect(rect);

    // No Brush Pattern
    rect.setRect(10, 240, 100, 100);
    brush.setStyle(Qt::NoBrush);
    painter.setBrush(brush);
    painter.drawRect(rect);

    // HorPattern
    rect.setRect(10, 360, 100, 100);
    brush.setStyle(Qt::HorPattern);
    painter.setBrush(brush);
    painter.drawRect(rect);

    // VerPattern
    rect.translate(110, 0);
    brush.setStyle(Qt::VerPattern);
    painter.setBrush(brush);
    painter.drawRect(rect);

    // CrossPattern
    rect.translate(110, 0);
    brush.setStyle(Qt::CrossPattern);
    painter.setBrush(brush);
    painter.drawRect(rect);

    // BDiagPattern
    rect.translate(110, 0);
    brush.setStyle(Qt::BDiagPattern);
    painter.setBrush(brush);
    painter.drawRect(rect);

    // FDiagPattern
    rect.translate(110, 0);
    brush.setStyle(Qt::FDiagPattern);
    painter.setBrush(brush);
    painter.drawRect(rect);

    // DiagCrossPattern
    rect.translate(110, 0);
    brush.setStyle(Qt::DiagCrossPattern);
    painter.setBrush(brush);
    painter.drawRect(rect);
}
