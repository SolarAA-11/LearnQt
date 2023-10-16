#ifndef WATERTANK_H
#define WATERTANK_H

#include <QWidget>
#include <QTimer>

/**
 * @brief The WaterTank class
 * Show real-time condition about water tank
 * In internal implementation, we use QPainter draw a graph
 * to illustrate this condition.
 *
 */
class WaterTank : public QWidget
{
    Q_OBJECT
public:
    explicit WaterTank(QWidget *parent = nullptr);

signals:
    void normal();
    void warning();
    void danger();

protected:
    void paintEvent(QPaintEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private slots:
    void onTimeOut();

private:
    void drawContainer(QPainter &painter);
    void drawWaterArea(QPainter &painter);

private:
    double m_water_height_percent;
    QTimer *m_timer;

};

#endif // WATERTANK_H
