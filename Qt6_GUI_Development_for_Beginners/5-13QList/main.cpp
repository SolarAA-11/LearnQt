#include <QCoreApplication>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Declare the list
    QList<QString> stringlist;

    // Put data in the list
    stringlist << "I am " << " lovin " << " Qt";
    stringlist.append(" a ");
    stringlist.append(" lot !");

    // Get the data from the list
    qDebug() << "The first element is " << stringlist[0];
    qDebug() << "The second element is " << stringlist[1];
    qDebug() << "The third element is " << stringlist[2];

    // Get the number of elements
    qDebug() << "The number of elements in my list is : " << stringlist.count();

    // Loop through the elements
    for(int i = 0; i < stringlist.count(); ++i) {
        qDebug() << "The element at index " << QString::number(i)
                 << " is " << stringlist.at(i);
    }

    return a.exec();
}
