#ifndef ADDITEMTOENTITY_H
#define ADDITEMTOENTITY_H

#include <QDialog>
#include <QStringListModel>

#include "../include/item.h"

namespace Ui
{
    class AddItemToEntity;
}

class AddItemToEntity : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Window constructor to add declared items to an entity inventory
     * @param [in] itemsBase The array of declared items
     * @param parent
     */
    explicit AddItemToEntity(const QVector<Item> & itemsBase, QWidget *parent = nullptr);
    ~AddItemToEntity();

    /**
     * @fn getItems
     * @brief Get the array of selected items to add to an entity
     * @return The array of selected items
     */
    QVector<Item> getItems();

private:
    /**
     * @brief The pointer to the window ui
     * @var ui
     */
    Ui::AddItemToEntity *ui;
    /**
     * @brief Declared items to be displayed
     * @var items
     */
    QVector<Item> items;
    /**
     * @brief Pointer to the model to display the items
     * @var model
     */
    QStringListModel * model;

    /**
     * @fn populate
     * @brief Used to make the model to display items with their names
     * @param items The item array that will be displayed
     * @return The array of all items names
     */
    QStringList populate(const QVector<Item> & items);
};

#endif // ADDITEMTOENTITY_H
