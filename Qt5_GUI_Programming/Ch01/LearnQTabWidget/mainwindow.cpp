#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton->setProperty("pagematches", false);
    ui->pushButton_2->setProperty("pagematches", false);
    ui->pushButton_3->setProperty("pagematches", false);

    int currentIndex = ui->tabWidget->currentIndex();
    switch (currentIndex) {
    case 0:
        ui->pushButton->setProperty("pagematches", true);
        break;
    case 1:
        ui->pushButton_2->setProperty("pagematches", true);
        break;
    case 2:
        ui->pushButton_3->setProperty("pagematches", true);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    // reset pushbutton's pagematches property to false
    // in order to set a proper style sheet
    ui->pushButton->setProperty("pagematches", false);
    ui->pushButton_2->setProperty("pagematches", false);
    ui->pushButton_3->setProperty("pagematches", false);

    switch (index) {
    case 0:
        ui->pushButton->setProperty("pagematches", true);
        break;
    case 1:
        ui->pushButton_2->setProperty("pagematches", true);
        break;
    case 2:
        ui->pushButton_3->setProperty("pagematches", true);
        break;
    default:
        break;
    }

    // refresh qstylesheet
    ui->pushButton->style()->polish(ui->pushButton);
    ui->pushButton_2->style()->polish(ui->pushButton_2);
    ui->pushButton_3->style()->polish(ui->pushButton_3);
}


void MainWindow::on_pushButton_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}



