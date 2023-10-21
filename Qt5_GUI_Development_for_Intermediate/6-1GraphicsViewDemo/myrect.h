#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>

class MyRect : public QGraphicsRectItem
{
public:
    MyRect();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // MYRECT_H
