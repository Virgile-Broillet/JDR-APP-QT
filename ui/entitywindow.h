#ifndef ENTITYWINDOW_H
#define ENTITYWINDOW_H

#include <QDialog>
#include <QWidget>
#include <QStringListModel>

#include "../include/entity.h"

namespace Ui
{
    class EntityWindow;
}

class EntityWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Window constructor to manage entities
     * @param [in] statsNamesBase Array of declared stats names
     * @param [in] entitiesBase Array of declared entities
     * @param [in] itemsBase Array of declared items
     * @param [in] skillsBase Array of declared skills
     * @param parent
     */
    explicit EntityWindow(const QVector<QString> & statsNamesBase,
                          const QVector<Entity> & entitiesBase,
                          const QVector<Item> & itemsBase,
                          const QVector<Skill> & skillsBase,
                          QWidget *parent = nullptr);
    ~EntityWindow();

    /**
     * @fn getEntities
     * @brief Get the entity array
     * @return The entity array modified by the user in the interface
     */
    QVector<Entity> getEntities();

private slots:
    /**
     * @fn add
     * @brief add a new entity to the current list and update the model
     */
    void add();
    /**
     * @fn modify
     * @brief modify the selected entity of the current list
     */
    void modify();
    /**
     * @fn remove
     * @brief remove the selected entity from the current list
     */
    void remove();
    /**
     * @fn load
     * @brief open the file explorer and load a previously saved entity in the current party
     */
    void load();
    /**
     * @fn save
     * @brief open the file explorer and save the selected entity
     */
    void save();
    /**
     * @fn addNewEntity
     * @brief add a new entity to the declared list of item in the game
     * @param toAdd The entity that will be added
     */
    void addNewEntity(Entity & toAdd);

private:
    /**
     * @brief Pointer to the window ui
     * @var ui
     */
    Ui::EntityWindow *ui;
    /**
     * @brief Copy array of declared entities in a game
     * @var entities
     */
    QVector<Entity> entities;
    /**
     * @brief Copy array of declared items in a game
     * @var items
     */
    QVector<Item> items;
    /**
     * @brief Copy array of declared skills in a game
     * @var skills
     */
    QVector<Skill> skills;
    /**
     * @brief Copy array of declared stats names in a game
     * @var statsNames
     */
    QVector<QString> statsNames;
    /**
     * @brief Pointer to the model to display existing entities
     * @var model
     */
    QStringListModel *model;

    /**
     * @fn populate
     * @brief Add all the names of the entity to the current list
     * @param [in] entities List of declared items in the game
     * @return An array of all entities name to make the model
     */
    QStringList populate(const QVector<Entity> & entities);
    /**
     * @fn updateModel
     * @brief update the listView model
     */
    void updateModel();
};

#endif // ENTITYWINDOW_H
