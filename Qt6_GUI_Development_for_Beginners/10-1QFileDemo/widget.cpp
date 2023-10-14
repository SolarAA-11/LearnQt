#include "widget.h"
#include "./ui_widget.h"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
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



// Write content of ui->textEdit to a chosen file
void Widget::on_writeButton_clicked()
{
    // choose a file
    QString fileName = QFileDialog::getSaveFileName(this, "Save As");

    if(fileName.isEmpty())
    {
        return;
    }

    // Open File
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text | QFile::Append))
    {
        return;
    }

    // Write to file
    QTextStream out(&file);
    out << ui->textEdit->toPlainText() << "\n";

    // Close File
    file.close();
}


void Widget::on_readButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File");
    if(fileName.isEmpty())
        return;

    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
        return;

    QTextStream in(&file);
    QString fileContent, lineContent;
    lineContent = in.readLine();
    while(!lineContent.isEmpty())
    {
        fileContent.append(lineContent + "\n");
        lineContent = in.readLine();
    }

    ui->textEdit->clear();
    ui->textEdit->setPlainText(fileContent);

    file.close();
}


void Widget::on_copyButton_clicked()
{
    QString sourceFileName = ui->sourceFileLineEdit->text();
    QString destinationFileName = ui->destinationFileLineEdit->text();

    if(sourceFileName.isEmpty() || destinationFileName.isEmpty())
        return;

    QFile sourceFile(sourceFileName);
    if(sourceFile.copy(destinationFileName))
    {
        QMessageBox::information(this, "Success", "Copy File Success");
    } else
    {
        QMessageBox::information(this, "Failed", "Copy File Failed");
    }
}


void Widget::on_selectButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Source File");
    ui->sourceFileLineEdit->setText(fileName);
    ui->destinationFileLineEdit->setText(fileName);
}

