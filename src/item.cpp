#include "../include/item.h"
#include <iostream>
using namespace std;

Item::Item() : Sheet::Sheet(){}
Item::Item(const QString name,
           const QString description,
           const QString texturePath,
           const QVector<Stat> & stats)
    : Sheet::Sheet(name, description, texturePath, stats){}
Item::~Item(){}

void Item::fillItemSpecs()
{
    string name, description;
    Item item;
    cout << "Quel nom voulez-vous donner à votre Item ? " << endl;
    cin >> name; item.name.fromStdString(name);
    cout << "Quelle description voulez-vous donner à "<< name << " ?" << endl;
    cin >> description; item.description.fromStdString(description);
}
void Item::showItemSpec(Item item)
{
    cout << "Votre Item s'appelle " << item.name.toStdString() << endl;
    cout << "Sa description est : " << endl;
    cout << item.description.toStdString() << endl;
}
