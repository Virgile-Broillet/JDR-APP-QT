#ifndef ADDITEMWINDOW_H
#define ADDITEMWINDOW_H

#include <QDialog>
#include <QStringListModel>

#include "../include/item.h"

namespace Ui {
class AddItemWindow;
}

class AddItemWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Window constructor to add an item
     * @param statsNamesBase the array of declared stats in the game
     * @param parent
     */
    explicit AddItemWindow(const QVector<QString> & statsNamesBase, QWidget *parent = nullptr);
    /**
     * @brief Window constructor to modify an item
     * @param statsNamesBase the array of declared stats in the game
     * @param itemBase The item that will be modified
     * @param parent
     */
    explicit AddItemWindow(const QVector<QString> & statsNamesBase, Item * itemBase, QWidget *parent = nullptr);
    ~AddItemWindow();

private slots:
    /**
     * @fn add
     * @brief Send an item to the declared list of item to be added to it
     */
    void add();
    /**
     * @fn modify
     * @brief Modify an item declared in the list of item
     */
    void modify();
    /**
     * @fn picture
     * @brief Set the picture filepath for one item
     */
    void picture();
    /**
     * @fn setMin
     * @brief Set the minimum of the stat currently selected in the combobox
     */
    void setMin();
    /**
     * @fn setValue
     * @brief Set the value of the stat currently selected in the combobox
     */
    void setValue();
    /**
     * @fn setMax
     * @brief Set the maximum of the stat currently selected in the combobox
     */
    void setMax();

signals:
    /**
     * @fn onItemAdded
     * @brief signal emitted when the add button is pressed
     * @param toAdd The item that will be added
     */
    void onItemAdded(Item & toAdd);

private:
    /**
     * @brief
     * @var ui
     */
    Ui::AddItemWindow *ui;
    /**
     * @brief
     * @var statsModel
     */
    QStringListModel * statsModel;
    /**
     * @brief Item made or modified by the user
     * @var current
     */
    Item current;
    /**
     * @brief Pointer to the item that will be modified
     * @var toModify
     */
    Item * toModify;
    /**
     * @brief Declared stats names
     * @var statsNames
     */
    QVector<QString> statsNames;

    /**
     * @fn populate
     * @brief Populate a list used to make the model of the combo box
     * @param statsNames
     * @return The list of stats names to init the model
     */
    QStringList populate(const QVector<QString> & statsNames);
    /**
     * @fn updateModel
     * @brief update the model for the combo box
     */
    void updateModel();
    /**
     * @fn resetStatsFields
     * @brief reset the stats fiels to the current value of each fields of an item for the selected stat in the combo box
     */
    void resetStatsFields();
};

#endif // ADDITEMWINDOW_H
