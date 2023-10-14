#include "widget.h"

#include <QApplication>
#include <QFile>

QString readTextFile(QString path)
{
    QFile file(path);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        return in.readAll();
    }

    return QString();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // :/styles/style.qss
    QString qss = readTextFile(":/styles/style.qss");
    if(!qss.isEmpty())
    {
        a.setStyleSheet(qss);
    }

    Widget w;
    w.show();
    return a.exec();
}
