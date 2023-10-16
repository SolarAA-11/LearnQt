#ifndef CHILDBUTTON_H
#define CHILDBUTTON_H

#include "parentbutton.h"

class ChildButton : public ParentButton
{
    Q_OBJECT
public:
    ChildButton(QWidget *parent = nullptr);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // CHILDBUTTON_H
