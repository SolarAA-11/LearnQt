#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileSystemModel>
#include <QStandardItemModel>

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
    void on_readDataButton_clicked();

private:
    Ui::Widget *ui;

    QFileSystemModel *m_dir_model;
    QStandardItemModel *m_standard_model;
};
#endif // WIDGET_H
