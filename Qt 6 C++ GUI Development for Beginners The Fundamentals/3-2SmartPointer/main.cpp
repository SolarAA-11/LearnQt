#include <QCoreApplication>
#include <QDebug>
#include <memory>

#include "house.h"

void do_stuff() {
    // stack memory
//    House h1(nullptr, "First");
//    h1.print_info();

    // heap memory
    //    House *p_h1 = new House(nullptr, "First");
    //    p_h1->print_info();
    //    delete p_h1;

    // Unique ptr
//    std::unique_ptr<House> up_house_1 {new House(nullptr, "Second")};
//    up_house_1->print_info();

    // Shared Ptr
    std::shared_ptr<House> sp_house_1 {new House(nullptr, "Third")};
    sp_house_1->print_info();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Starting...";
    do_stuff();
    qDebug() << "Ending...";

    return a.exec();
}
