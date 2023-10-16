#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int argc, char **argv);

    // QCoreApplication interface
public:
    bool notify(QObject *, QEvent *) override;
};

#endif // APPLICATION_H
