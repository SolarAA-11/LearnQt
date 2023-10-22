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
    void on_xTranslateSpinBox_valueChanged(int arg1);

    void on_yTranslateSpinBox_valueChanged(int arg1);

    void on_xScaleSpinBox_valueChanged(int arg1);

    void on_yScaleSpinBox_valueChanged(int arg1);

    void on_xShearSpinBox_valueChanged(int arg1);

    void on_yShearSpinBox_valueChanged(int arg1);

    void on_rotationSpinBox_valueChanged(int arg1);

private:
    QGraphicsItem *getSelectedItem() const;

    Ui::Widget *ui;
    QGraphicsScene *m_scene;
};
#endif // WIDGET_H
