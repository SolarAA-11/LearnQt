#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>>

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
    void on_lineButton_clicked();

    void on_ellipseButton_clicked();

    void on_pathButton_clicked();

    void on_pieButton_clicked();

    void on_imageButton_clicked();

    void on_starButton_clicked();

private:
    Ui::Widget *ui;
    QGraphicsScene *m_scene;
};
#endif // WIDGET_H
