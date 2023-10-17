#ifndef INDICATOR_H
#define INDICATOR_H

#include <QWidget>
#include <QTimer>
#include <QPainter>

/**
 * @brief The Indicator class
 * A light containing three different color light which will shimmer
 *
 */
class Indicator : public QWidget
{
    Q_OBJECT
public:
    explicit Indicator(QWidget *parent = nullptr);

public slots:
    void setLightGreen() {
        m_light_state = LightState::Green;
        update();
    }
    void setLightYellow() {
        m_light_state = LightState::Yellow;
        update();
    }
    void setLightRed() {
        m_light_state = LightState::Red;
        update();
    }

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void onTimeOut();

private:
    enum LightState {
        Green,
        Yellow,
        Red,
    };

    LightState m_light_state;
    bool m_light_on;
    QTimer *m_timer;
};

#endif // INDICATOR_H
