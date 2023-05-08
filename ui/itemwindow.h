#ifndef ITEMWINDOW_H
#define ITEMWINDOW_H

#include <QDialog>
#include <QWidget>
#include <QStringListModel>

#include "../include/item.h"

namespace Ui
{
    class ItemWindow;
}

class ItemWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Window constructor to manage items
     * @param [in] statsNamesBase Array of desclared stats names
     * @param [in] items Array of declared items
     * @param parent
     */
    explicit ItemWindow(const QVector<QString> & statsNamesBase, const QVector<Item> & items, QWidget *parent = nullptr);
    ~ItemWindow();

    /**
     * @fn getItems
     * @brief Get the items array
     * @return The items array modified by the user in the interface
     */
    QVector<Item>getItems();

private slots:
    /**
     * @fn add
     * @brief add a new item to the current list and update the model
     */
    void add();
    /**
     * @fn modify
     * @brief modify the selected item of the current list
     */
    void modify();
    /**
     * @fn remove
     * @brief remove the selected item from the current list
     */
    void remove();
    /**
     * @fn load
     * @brief open the file explorer and load a previously saved item in the current party
     */
    void load();
    /**
     * @fn save
     * @brief open the file explorer and save the selected item
     */
    void save();
    /**
     * @fn addNewItem
     * @brief add a new item to the declared list of item in the game
     * @param toAdd The item that will be added
     */
    void addNewItem(Item & toAdd);

private:
    /**
     * @brief Pointer to the window ui
     * @var ui
     */
    Ui::ItemWindow *ui;
    /**
     * @brief Array of items
     * @var items
     */
    QVector<Item> items;
    /**
     * @brief Array of stats names
     * @var statsNames
     */
    QVector<QString> statsNames;
    /**
     * @brief Pointer to the model to display existing items
     * @var model
     */
    QStringListModel *model;
    /**
     * @fn populate
     * @brief add all the names of the items to a QString list
     * @param items List of declared items in the game
     * @return An array of all items name to make the model
     */
    QStringList populate(const QVector<Item> & items);
    /**
     * @fn updateModel
     * @brief update the listView model
     */
    void updateModel();
};

#endif // ITEMWINDOW_H
