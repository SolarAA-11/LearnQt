#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDialog>

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
    void on_openDialogButton_clicked();

    void on_showModalDialogButton_clicked();

    void on_showModelessDialogButton_clicked();

private:
    Ui::Widget *ui;
    QDialog *m_dialog;

    QDialog *m_modelessDialog;
    QPoint m_modelessDialogPosition;
};
#endif // WIDGET_H
