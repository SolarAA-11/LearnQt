#include "widget.h"
#include "./ui_widget.h"

#include <QFileDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_chooseDirButton_clicked()
{
    QString dirPath = QFileDialog::getExistingDirectory(this, "Choose a folder");
    if(dirPath.isEmpty())
        return;
    ui->lineEdit->setText(dirPath);
}


void Widget::on_creatDirButton_clicked()
{
    QString dirPath = ui->lineEdit->text();
    if(dirPath.isEmpty())
        return;

    QDir dir(dirPath);
    if(!dir.exists())
    {
        if(dir.mkpath(dirPath))
        {
            QMessageBox::information(this, "Message", "Directory Created");
        }
    } else
    {
        QMessageBox::information(this, "Message", "Directory already exists");
    }


}


void Widget::on_dirExistsButton_clicked()
{
    QString dirPath = ui->lineEdit->text();
    QDir dir(dirPath);
    if(dir.exists())
    {
        QMessageBox::information(this, "Message", "Dir Exists!");
    } else
    {
        QMessageBox::information(this, "Message", "Dir doesn't exist!");
    }
}


void Widget::on_dirOrFileButton_clicked()
{
    QFileInfo fileInfo(ui->listWidget->currentItem()->text());

    if(fileInfo.isDir())
    {
        QMessageBox::information(this, "Message", "This is a folder");
    } else if (fileInfo.isFile())
    {
        QMessageBox::information(this, "Message", "This is a file");
    } else
    {
        QMessageBox::information(this, "Message", "Something else");
    }
}


void Widget::on_folderContentButton_clicked()
{
    QString dirPath = ui->lineEdit->text();
    if(dirPath.isEmpty())
        return;

    QDir dir(dirPath);
    QList<QFileInfo> entryList = dir.entryInfoList();

    ui->listWidget->clear();
    for(auto entryInfo: entryList)
    {
        ui->listWidget->addItem(entryInfo.absoluteFilePath());
    }
}

