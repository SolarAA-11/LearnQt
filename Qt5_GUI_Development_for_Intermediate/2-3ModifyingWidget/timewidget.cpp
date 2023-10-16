#include "timewidget.h"

#include <QTime>
#include <QDate>

TimeWidget::TimeWidget(QWidget *parent)
    : QWidget{parent}
{
    // UI
    m_label_1 = new QLabel();
    m_label_1->setText(QDate::currentDate().toString());

    m_label_2 = new QLabel();
    m_label_2->setText(QTime::currentTime().toString());

    m_layout = new QVBoxLayout();
    m_layout->addWidget(m_label_1);
    m_layout->addWidget(m_label_2);
    setLayout(m_layout);

    // Timer
    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    m_timer->start();
    connect(m_timer, &QTimer::timeout, this, &TimeWidget::on_timeout);
}

void TimeWidget::on_timeout()
{
    // update label
    m_label_1->setText(QDate::currentDate().toString());
    m_label_2->setText(QTime::currentTime().toString());
}
