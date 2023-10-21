#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>

class MyScene : public QGraphicsScene
{
public:
    explicit MyScene(QObject *parent = nullptr);
};

#endif // MYSCENE_H
