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

void InfoDialog::on_okButton_clicked()
{
    QString user_position = ui->positionEdit->text();

    if(!user_position.isEmpty()) {
        m_position = user_position;

        if(ui->windowRadioButton->isChecked()) {
            m_favorite_os = "Windows";
        } else if(ui->linuxRadioButton->isChecked()) {
            m_favorite_os = "Linux";
        } else {
            m_favorite_os = "Mac";
        }

        // Accept Dialog
        accept();
    } else {
        // Reject Dialog
        reject();
    }
}


void InfoDialog::on_cancelButton_clicked()
{
    // Reject this dialog
    reject();
}

QString InfoDialog::position() const
{
    return m_position;
}

QString InfoDialog::favorite_os() const
{
    return m_favorite_os;
}

