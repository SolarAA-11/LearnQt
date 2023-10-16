#ifndef PARENTBUTTON_H
#define PARENTBUTTON_H

#include <QWidget>
#include <QPushButton>

class ParentButton : public QPushButton
{
    Q_OBJECT
public:
    ParentButton(QWidget *parent = nullptr);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // PARENTBUTTON_H
