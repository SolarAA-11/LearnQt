#include "widget.h"
#include "./ui_widget.h"

#include <QDebug>
#include <random>
#include <ctime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Initialize rand seed
    std::srand(std::time(nullptr));

    // Generate secret number
    secret_number = std::rand() % 10 + 1;
    qDebug() << "Secret number is: " << secret_number;

    // Disable start over button
    ui->startOverButton->setDisabled(true);

    // Clear message label
    ui->messageLabel->setText("");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_guessButton_clicked()
{
    guess_number = ui->numberSpinBox->value();
    qDebug() << "User guess number is: " << guess_number;

    if (guess_number == secret_number) {
        // show the congratulation message
        ui->messageLabel->setText(
            "Congratulation, the number is " + QString::number(secret_number));

        // Button
        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);
    } else {
        if (guess_number < secret_number) {
            ui->messageLabel->setText("The guess number is lower than the secret number");
        } else if (guess_number > secret_number) {
            ui->messageLabel->setText("The guess number is larger than the secret number");
        }
    }
}


void Widget::on_startOverButton_clicked()
{
    // set button disable state
    ui->guessButton->setDisabled(false);
    ui->startOverButton->setDisabled(true);

    // regenerate secret number
    secret_number = rand() % 10 + 1;

    // clear message label
    ui->messageLabel->clear();
}

