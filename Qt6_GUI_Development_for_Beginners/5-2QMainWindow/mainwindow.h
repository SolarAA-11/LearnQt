#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

private slots:
    void btn_clicked();

    // QWidget interface
private:
    QSize sizeHint() const;

private:
    QAction *quitAction;
};

#endif // MAINWINDOW_H
