#include "colorpicker.h"

#include <QList>
#include <QPushButton>
#include <QPalette>

ColorPicker::ColorPicker(QWidget *parent)
    : QWidget{parent}
{
    // Init color list
    m_color_list << Qt::red
                 << Qt::green
                 << Qt::blue
                 << Qt::cyan
                 << Qt::darkRed
                 << Qt::darkGray
                 << Qt::gray
                 << Qt::yellow
                 << Qt::darkYellow;

    // Button List
    QList<QPushButton*> button_list;
    for(size_t i = 0; i < 9; ++i)
    {
        QString text = QString("Button %0").arg(i);
        QPushButton *btn = new QPushButton(text, this);
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        // Don't know why QPalette can't work
//        QPalette palette = btn->palette();
//        palette.setColor(QPalette::Button, m_color_list[i]);
//        btn->setAutoFillBackground(true);
//        btn->setPalette(palette);
//        btn->update();

        QString qss = QString("background-color: %1").arg(m_color_list[i].name());
        btn->setStyleSheet(qss);

        button_list.append(btn);
    }

    // QLabel
    m_label = new QLabel("Color", this);

    // Layout
    m_layout = new QGridLayout(this);
    m_layout->addWidget(m_label, 0, 0, 1, 3);

    for(size_t i = 0; i < 3; ++i)
    {
        for(size_t j = 0; j < 3; ++j)
        {
            m_layout->addWidget(button_list[i * 3 + j], i +  1, j);
        }
    }

    setLayout(m_layout);

    // Add buttons to button group
    m_button_group = new QButtonGroup(this);
    for(size_t index = 0; index < 9; ++index)
    {
        m_button_group->addButton(button_list[index]);
        m_button_group->setId(button_list[index], index);
    }

    // Connect idClicked Signal
//    connect(m_button_group, &QButtonGroup::idClicked, [=](int id){
//        QString qss = QString("background-color: %1").arg(m_color_list[id].name());
//        m_label->setStyleSheet(qss);
//    });

    connect(m_button_group, &QButtonGroup::buttonClicked, [=](QAbstractButton *btn){
        int index = m_button_group->id(btn);
        if(index != -1)
        {
            // Set QLabel Color
            QString qss = QString("background-color: %1").arg(m_color_list[index].name());
            m_label->setStyleSheet(qss);
        }
    });
}
