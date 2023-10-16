#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QWidget>
#include <QColor>
#include <QButtonGroup>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QList>
#include <QColor>

class ColorPicker : public QWidget
{
    Q_OBJECT
public:
    explicit ColorPicker(QWidget *parent = nullptr);

signals:
    void colorChanged(QColor color);

private:
    QButtonGroup *m_button_group;
    QLabel *m_label;
    QGridLayout *m_layout;
    QList<QColor> m_color_list;
};

#endif // COLORPICKER_H
