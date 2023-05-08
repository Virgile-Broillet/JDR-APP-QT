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
     * @param [in] name The name of the item
     * @param [in] description The description of the item
     * @param [in] texturePath The texturePath of the item
     * @param [in] stats The stats array of the item
     */
    Item(const QString & name,
         const QString & description,
         const QString & texturePath,
         const QVector<Stat> & stats);
    ~Item();
    /**
     * @fn addItemToArray
     * @brief Add the item to an array
     * @param [in] itemsArray The array where the item will be added
     */
    void addItemToArray(QVector<Item> & itemsArray);

private:
    /**
     * @fn showItemSpec
     * @brief (LEGACY) Show the name and the desc of an object in the console
     * @param [in] item The info of this item will be shown
     */
    void showItemSpec(Item item);
    /**
     * @fn fillItemSpecs
     * @brief (LEGACY) Fill the name and the desc of an object in the terminal
     */
    void fillItemSpecs();
};

#endif
