#ifndef OBJECT_H
#define OBJECT_H

#include <QString>
#include "../include/sheet.h"

using namespace std;

class Item : public Sheet
{
public:
    /**
     * @brief empty constructor of Item class
     */
    Item();
    /**
     * @brief Initiliazed Item class constructor
     * @param name of the item
     * @param description of the item
     * @param texturePath of the item
     * @param stats array of the item
     */
    Item(const QString name,
         const QString description,
         const QString texturePath,
         const QVector<Stat> & stats);
    /**
     * @brief Destroyer of class
     */
    ~Item();

private:
    /**
     * @brief Show the name and the desc of an object in a textual version
     * @param item
     */
    void showItemSpec(Item item);
    /**
     * @brief Fill the name and the desc of an object in a textual version
     */
    void fillItemSpecs();
};

#endif
