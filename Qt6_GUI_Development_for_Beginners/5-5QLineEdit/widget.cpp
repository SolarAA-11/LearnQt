#include "widget.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // First Name
    QLabel *first_name_label = new QLabel("First Name: ", this);
    first_name_label->setMinimumSize(70, 50);
    first_name_label->move(10, 10);

    QLineEdit *first_name_lineedit = new QLineEdit(this);
    first_name_lineedit->setMinimumSize(200, 50);
    first_name_lineedit->move(100, 10);

    // Lastname
    QLabel *last_name_label = new QLabel("Last Name: ", this);
    last_name_label->setMinimumSize(70, 50);
    last_name_label->move(10, 70);

    QLineEdit *last_name_lineedit = new QLineEdit(this);
    last_name_lineedit->setMinimumSize(200, 50);
    last_name_lineedit->move(100, 70);

    // City
    QLabel *city_label = new QLabel("City: ", this);
    city_label->setMinimumSize(70, 50);
    city_label->move(10, 130);

    QLineEdit *city_lineedit = new QLineEdit(this);
    city_lineedit->setMinimumSize(200, 50);
    city_lineedit->move(100, 130);

    // Grab Button
    QFont btn_font("Times", 20, QFont::Bold);
    QPushButton *grab_btn = new QPushButton("Grab", this);
    grab_btn->setFont(btn_font);
    grab_btn->move(80, 190);

    // connect
    connect(grab_btn, &QPushButton::clicked, [=](){
        QString firstName = first_name_lineedit->text();
        QString lastName = last_name_label->text();
        QString city = city_lineedit->text();

        if (!firstName.isEmpty() && !lastName.isEmpty() && !city.isEmpty()) {
            qDebug() << "First Name is: " << firstName;
            qDebug() << "Last Name is : " << lastName;
            qDebug() << "City Name is : " << city;
        } else {
            qDebug() << "Some fields are empty";
        }
    });

    // Connect QLineEdit Signals

    // cursorPositionChanged
    connect(first_name_lineedit, &QLineEdit::cursorPositionChanged, [=](int oldPos, int newPos){
        qDebug() << "oldPos: " << oldPos << ", newPos" << newPos;
    });
}

Widget::~Widget()
{
}

