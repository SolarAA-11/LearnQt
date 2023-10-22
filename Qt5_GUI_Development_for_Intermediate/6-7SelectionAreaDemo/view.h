#ifndef VIEW_H
#define VIEW_H

#include <optional>

#include <QWidget>
#include <QGraphicsView>
#include <QPointF>
#include <QGraphicsPolygonItem>
#include <QGraphicsRectItem>

/**
 * @brief The View class
 *
 * 1. draw background gray
 * 2. draw foreground axies line
 *
 * Beyond that two appearance features, this widget
 * supports selection area
 */
class View : public QGraphicsView
{
public:
    View(QWidget *parent = nullptr);

    // QGraphicsView interface
    bool isDrawForeground() const;
    void setIsDrawForeground(bool newIsDrawForeground);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void drawForeground(QPainter *painter, const QRectF &rect) override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    bool m_isDrawForeground;
    std::optional<QPointF> m_selectAreaLeftTop; // this coordinate is from view's coordinate system
    QGraphicsPolygonItem *m_polygonSelectAreaItem;
};

#endif // VIEW_H
