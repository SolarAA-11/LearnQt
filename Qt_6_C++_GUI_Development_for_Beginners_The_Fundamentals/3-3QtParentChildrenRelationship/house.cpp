#include "house.h"

#include <QDebug>

House::House(QObject *parent, const QString &description)
    : QObject{parent}, m_descr(description)
{
    qDebug() << "House Object Constructed";
}

House::~House()
{
    qDebug() << "House Object Destroied: " << m_descr;
}

void House::print_info() const
{
    qDebug() << "House Info: " << m_descr;
}
