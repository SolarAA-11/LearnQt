#include <QCoreApplication>
#include <QDebug>
#include "house.h"

void do_stuff() {
    House *p_parent = new House(nullptr, "Parent");
    House *p_child1 = new House(p_parent, "Child1");
    House *p_child2 = new House(p_child1, "Child2");
    delete p_parent;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Starting...";
    do_stuff();
    qDebug() << "Ending...";
    return a.exec();
}
