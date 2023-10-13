#include "rockwidget.h"

#include <QMessageBox>
#include <QLabel>
#include <QPalette>
#include <QPushButton>

RockWidget::RockWidget(QWidget *parent)
    : QWidget{parent}
{

    QLabel *label = new QLabel(this);
    label->setText("First Line\nSecond Line");
    label->move(50, 50);

    QPalette label1Palette;
    label1Palette.setColor(QPalette::Window, Qt::yellow);
    label1Palette.setColor(QPalette::WindowText, Qt::black);

    QFont label1Font("Times", 20, QFont::Bold);

    QLabel *label1 = new QLabel(this);
    label1->setAutoFillBackground(true);
    label1->setText("My colored label!");
    label1->setFont(label1Font);
    label1->setPalette(label1Palette);
    label1->move(150, 150);

    QFont buttonFont("Times", 30, QFont::Bold);
    QPushButton *button = new QPushButton(this);
    button->setText("Click Me");
    button->setFont(buttonFont);
    button->move(100, 250);
    connect(button, SIGNAL(clicked()), this, SLOT(button_clicked()));
}

void RockWidget::button_clicked()
{
    QMessageBox::information(this, "Messsage", "You clicked on my button");
}

QSize RockWidget::sizeHint() const
{
    return QSize(500, 500);
}
