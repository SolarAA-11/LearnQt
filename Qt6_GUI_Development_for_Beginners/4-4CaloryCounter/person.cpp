#include "person.h"

Person::Person(QObject *parent)
    : QObject{parent}
{

}

void Person::setWeight(double weight)
{
    m_weight = weight;
}
