#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}


void InfoDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    auto stdButton = ui->buttonBox->standardButton(button);
    if(stdButton == QDialogButtonBox::Ok) {
        accept();
        qDebug() << "OK Button Clicked";
    }
}

