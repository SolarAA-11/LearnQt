#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsScene>

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
    void on_showHideButton_clicked();

    void on_removeButton_clicked();

private:
    Ui::Widget *ui;
    QGraphicsRectItem *m_parentRect;
    QGraphicsScene *m_scene;
};
#endif // WIDGET_H
