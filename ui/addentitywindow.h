#ifndef ADDENTITYWINDOW_H
#define ADDENTITYWINDOW_H

#include <QDialog>
#include <QStringListModel>

#include "../include/entity.h"

namespace Ui
{
    class AddEntityWindow;
}

class AddEntityWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Window constructor to add an entity
     * @param [in] statsNamesBase the array of declared stats in the game
     * @param [in] itemsBase Array of declared item of a game
     * @param [in] skillsBase Array of declared skill of a game
     * @param parent
     */
    explicit AddEntityWindow(const QVector<QString> & statsNamesBase,
                             const QVector<Item> & itemsBase,
                             const QVector<Skill> & skillsBase,
                             QWidget *parent = nullptr);
    /**
     * @brief  Window constructor to modify an entity
     * @param [in] statsNamesBase the array of declared stats in the game
     * @param [in] entityBase The entity that will be modified
     * @param [in] itemsBase Array of declared item of a game
     * @param [in] skillsBase Array of declared skill of a game
     * @param parent
     */
    explicit AddEntityWindow(const QVector<QString> & statsNamesBase,
                             const QVector<Item> & itemsBase,
                             const QVector<Skill> & skillsBase,
                             Entity * entityBase,
                             QWidget *parent = nullptr);
    ~AddEntityWindow();

private slots:
    /**
     * @fn add
     * @brief Send an entity to the declared list of entity
     */
    void add();
    /**
     * @fn modify
     * @brief Modify an entity declared in the list of entity
     */
    void modify();
    /**
     * @fn picture
     * @brief Set the picture filepath for one entity
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
    /**
     * @fn setInventorySlots
     * @brief Set the number of slots an entity have in its inventory
     */
    void setInventorySlots();
    /**
     * @fn addToItemsInventory
     * @brief Open a new window to select all items to add to the inventory
     */
    void addToItemsInventory();
    /**
     * @fn removeFromItemsInventory
     * @brief Remove an item from the currently edited entity
     */
    void removeFromItemsInventory();
    /**
     * @fn addToSkillsInventory
     * @brief Open a new window to select all items to add to the entity's skills
     */
    void addToSkillsInventory();
    /**
     * @fn removeFromSkillsInventory
     * @brief Remove a skill from the currently edited entity
     */
    void removeFromSkillsInventory();

signals:
    /**
     * @fn onEntityAdded
     * @brief signal emitted when the add button is pressed
     * @param toAdd The item that will be added
     */
    void onEntityAdded(Entity & toAdd);

private:
    /**
     * @brief Pointer to the window ui
     * @var ui
     */
    Ui::AddEntityWindow *ui;
    /**
     * @brief Used to display stats names
     * @var statsModel
     */
    QStringListModel * statsModel;
    /**
     * @brief Used to display current inventory
     * @var inventoryModel
     */
    QStringListModel * inventoryModel;
    /**
     * @brief Used to display currently possed skills
     * @var skillsModel
     */
    QStringListModel * skillsModel;
    /**
     * @brief Declared stats names
     * @var statsNames
     */
    QVector<QString> statsNames;
    /**
     * @brief Item made or modified by the user
     * @var current
     */
    Entity current;
    /**
     * @brief Pointer to the item that will be modified
     * @var toModify
     */
    Entity * toModify;
    /**
     * @brief Copy of declared items in game
     * @var items
     */
    QVector<Item> items;
    /**
     * @brief Copy of declared skills in game
     * @var skills
     */
    QVector<Skill> skills;

    /**
     * @fn populate
     * @brief Populate a list used to make the model of the combo box
     * @param [in] statsNames The array of declared stats names
     * @return The list of stats names to init the model
     */
    QStringList populate(const QVector<QString> & statsNames);
    /**
     * @fn resetStatsFields
     * @brief reset the stats fiels to the current value of each fields of an entity for the selected stat in the combo box
     */
    void resetStatsFields();
    /**
     * @fn updateInventoryModel
     * @brief Update inventory display
     */
    void updateInventoryModel();
    /**
     * @fn updateSkillsModel
     * @brief Update the skills display
     */
    void updateSkillsModel();
};

#endif // ADDENTITYWINDOW_H
