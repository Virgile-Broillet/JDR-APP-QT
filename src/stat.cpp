#include "../include/stat.h"
#include <QString>

Stat::Stat(){};
Stat::Stat(const QString &name, const int min, const int max, const int value)
{
    this->min = min;
    this->max = max;
    this->val = value;
    this->name = name;
}
Stat::Stat(const QString &name)
{
    this->min = 0;
    this->max = 0;
    this->val = 0;
    this->name = name;
}
Stat::~Stat()
{

}
int Stat::getMin()const
{
    return this->min;
}
int Stat::getMax()const
{
    return this->max;
}
int Stat::getValue()const
{
    return this->val;
}
QString Stat::getName()const
{
    return this->name;
}
void Stat::setMin(const int min)
{
    this->min = min;
}
void Stat::setMax(const int max)
{
    this->max = max;
}
void Stat::setValue(const int val)
{
    this->val = val;
}
void Stat::setName(const QString & name)
{
    this->name = name;
}
bool Stat::operator==(const QString name) const
{
    return (this->name.compare(name) == 0);
}
