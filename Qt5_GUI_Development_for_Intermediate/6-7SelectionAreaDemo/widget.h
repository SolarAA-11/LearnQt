#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_centerViewButton_clicked();

    void on_showGridCheckBox_toggled(bool checked);

    void on_fitInViewButton_clicked();

    void on_zoomInButton_clicked();

    void on_zoomOutButton_clicked();

    void on_resetButton_clicked();

    void on_ensureVisibleButton_clicked();

private:
    Ui::Widget *ui;
    QGraphicsScene *m_scene;

    QGraphicsItem *m_item1;
    QGraphicsItem *m_item2;
    QGraphicsItem *m_item3;
};
#endif // WIDGET_H
