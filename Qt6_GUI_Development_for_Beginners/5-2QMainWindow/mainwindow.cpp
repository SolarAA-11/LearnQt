#include "mainwindow.h"

#include <QPushButton>
#include <QMessageBox>
#include <QAction>
#include <QApplication>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    // Add central widget
    QPushButton *btn = new QPushButton("Hello", this);
    setCentralWidget(btn);

    connect(btn, &QPushButton::clicked,
            this, &MainWindow::btn_clicked);

    // declare menu bar and qaction
    quitAction = new QAction("Quit");
    connect(quitAction, &QAction::triggered, [=](){
        QApplication::quit();
    });

    // Add menu
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("window");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");

    // Add message to status bar
    statusBar()->showMessage("Uploading file...", 3000);
}

void MainWindow::btn_clicked()
{
    QMessageBox::information(this, "Button Clicked", "You clicked central button");
}


QSize MainWindow::sizeHint() const
{
    return QSize(800, 500);
}
