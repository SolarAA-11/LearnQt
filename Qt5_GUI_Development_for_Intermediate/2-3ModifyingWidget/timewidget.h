#ifndef TIMEWIDGET_H
#define TIMEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>

/**
 * A widget show date and time
 * Two labels:
 * 1. m_label_top shows date
 * 2. m_label_bottom shows time
 *
 * One Layout:
 * 1. QVBoxLayout
 *
 * A timer:
 * 1. m_timer refresh time information
 *
 * A slos:
 * 1. on_timeout react to m_timer's signal timeout
 * */
class TimeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TimeWidget(QWidget *parent = nullptr);

private slots:
    void on_timeout();

private:
    QLabel *m_label_1;
    QLabel *m_label_2;
    QVBoxLayout *m_layout;
    QTimer *m_timer;
};

#endif // TIMEWIDGET_H
