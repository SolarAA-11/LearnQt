#include "widget.h"
#include "./ui_widget.h"
#include "infodialog.h"

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


void Widget::on_provideInfoButton_clicked()
{
    InfoDialog *dialog = new InfoDialog(this);

    // Show Dialog in Modal Dialog Mode
//    auto ret = dialog->exec();

//    if(ret == QDialog::Accepted) {
//        QString position = dialog->position();
//        QString os = dialog->favorite_os();

//        qDebug() << "Dialog accepted, position is: " << position
//                 << " and favorite os is : " << os;
//        ui->infoLabel->setText("Your position is : " + position
//                               + ", Your favorite os is : " + os);
//    } else {
//        ui->infoLabel->setText("Dialog rejected");
//    }

    // Show Dialog in Non Modal Dialog Mode
    connect(dialog, &InfoDialog::accepted, [=](){
        QString position = dialog->position();
        QString os = dialog->favorite_os();

        qDebug() << "Dialog accepted, position is: " << position
                 << " and favorite os is : " << os;
        ui->infoLabel->setText("Your position is : " + position
                               + ", Your favorite os is : " + os);
    });
    connect(dialog, &InfoDialog::rejected, [=](){
        ui->infoLabel->setText("Dialog rejected");
    });
    dialog->show();
}

