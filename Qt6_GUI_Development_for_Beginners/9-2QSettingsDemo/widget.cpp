#include "widget.h"
#include "./ui_widget.h"

#include <QSettings>
#include <QColorDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    for(int i = 0; i < 9; ++i)
        m_color_list.append(Qt::black);

    on_loadButton_clicked();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_1_clicked()
{
    choose_button_color(0, ui->pushButton_1);
}


void Widget::on_pushButton_2_clicked()
{
    choose_button_color(1, ui->pushButton_2);
}


void Widget::on_pushButton_3_clicked()
{
    choose_button_color(2, ui->pushButton_3);
}


void Widget::on_pushButton_4_clicked()
{
    choose_button_color(3, ui->pushButton_4);
}


void Widget::on_pushButton_5_clicked()
{
    choose_button_color(4, ui->pushButton_5);
}


void Widget::on_pushButton_6_clicked()
{
    choose_button_color(5, ui->pushButton_6);
}


void Widget::on_pushButton_7_clicked()
{
    choose_button_color(6, ui->pushButton_7);
}


void Widget::on_pushButton_8_clicked()
{
    choose_button_color(7, ui->pushButton_8);
}


void Widget::on_pushButton_9_clicked()
{
    choose_button_color(8, ui->pushButton_9);
}


// Save all button color to a QSettings
void Widget::on_saveButton_clicked()
{
    for(int i = 0;i < 9;++i) {
        QString button_object_name = QString("pushbutton_%1").arg(i + 1);
        save_color(button_object_name, m_color_list[i]);
    }
}

// Load button colors and set color to all buttons
void Widget::on_loadButton_clicked()
{
    set_loaded_color("pushbutton_1", 0, ui->pushButton_1);
    set_loaded_color("pushbutton_2", 1, ui->pushButton_2);
    set_loaded_color("pushbutton_3", 2, ui->pushButton_3);
    set_loaded_color("pushbutton_4", 3, ui->pushButton_4);
    set_loaded_color("pushbutton_5", 4, ui->pushButton_5);
    set_loaded_color("pushbutton_6", 5, ui->pushButton_6);
    set_loaded_color("pushbutton_7", 6, ui->pushButton_7);
    set_loaded_color("pushbutton_8", 7, ui->pushButton_8);
    set_loaded_color("pushbutton_9", 8, ui->pushButton_9);
}

// key: QPushButton's Object Name
void Widget::save_color(QString key, QColor color)
{
    int red = color.red();
    int blue = color.blue();
    int green = color.green();

    QSettings settings("SolarAA", "SettingsDemo");
    settings.beginGroup("ButtonColor");
    settings.setValue(key + "r", red);
    settings.setValue(key + "b", blue);
    settings.setValue(key + "g", green);
    settings.endGroup();
}

QColor Widget::load_color(QString key)
{
    QSettings settings("SolarAA", "SettingsDemo");

    settings.beginGroup("ButtonColor");
    int red = settings.value(key + "r", QVariant(0)).toInt();
    int blue = settings.value(key + "b", QVariant(0)).toInt();
    int green = settings.value(key + "g", QVariant(0)).toInt();
    settings.endGroup();

    return QColor(red, green ,blue);
}

void Widget::set_loaded_color(QString key, int index, QPushButton *button)
{
    QColor color = load_color(key);
    m_color_list[index] = color;
    QString qss = QString("background-color: %1").arg(color.name());
    button->setStyleSheet(qss);
}

void Widget::choose_button_color(int index, QPushButton *button)
{
    QColor color = QColorDialog::getColor(
        m_color_list[index], this, "Choose background color");
    if(color.isValid())
    {
        m_color_list[index] = color;

        QString qss = QString("background-color: %1").arg(color.name());
        button->setStyleSheet(qss);
    }
}

