#ifndef ENTITY_H
#define ENTITY_H

#include <QString>
#include <QList>
#include <QObject>

#include "skill.h"
#include "item.h"
#include "sheet.h"

class Entity : public Sheet
{
public:
    Entity();
    /**
     * @brief Entity copy constructor
     * @param[in] entity to copy
     */
    Entity(const Entity & entity);
    /**
     * @brief Entity constructor with complete initialization
     * @param[in] name of an entity
     * @param[in] description of an entity
     * @param[in] type of an entity
     * @param[in] texturePath of an entity
     * @param[in] inventoryMaxSlot of an entity
     * @param[in] stats to add to the new entity
     * @param[in] inventory to add to the new entity
     * @param[in] skills to add to the new entity
     */
    Entity(const QString name,
           const QString description,
           const QString type,
           const QString texturePath,
           const unsigned int inventoryMaxSlot,
           const QVector<Stat> & stats,
           const QVector<Item> & inventory,
           const QVector<Skill> & skills);
    ~Entity();

    /**
     @fn getInventory
     @brief get the inventory of the entity
     @returns returns the Entity's Inventory in the form of an array;
     */
    QList<Item> getInventory()const;
    /**
     @fn addToInventory
     @brief Add an item to the inventory of the entity
     @param[in] item
     */
    void addToInventory(const Item item);
    /**
     * @fn updateInventory
     * @brief resize the inventory, if there is more item than the targeted size, they will be lost
     * @param[in] size targeted size
     */
    void updateInventorySize(const unsigned int size);
    /**
     * @fn addSkill
     * @brief add a skill to an entity
     * @param[in] skill the skill to add
     */
    void addSkill(const Skill skill);
    /**
     * @brief Entity::getTypeOfEntity
     * @return type of entity
     */
    QString getType()const;
    /**
     * @brief Entity::setTypeOfEntity
     * @param typeOfEntity
     */
    void setType(const QString type);
    /**
     @fn getTexturePath
     @brief get the texture path
     @returns texturePath
     */
    QString getTexturePath()const;
    /**
     * @fn setTexturePath
     * @brief set the texture path
     * @param[in] texturePath
     */
    void setTexturePath(const QString texturePath);
    /**
     * @brief show all the specs of an entity in a terminal
     * @param entity
     */
    void showEntitySpec();
    /**
     * @brief use to enter all the parameters of an entity
     * @var entity
     */
    void fillEntitySpec();
    /**
     * @fn setInventorySlots
     * @brief change the number of inventory slot
     * @param inventorySolts
     */
    void setInventorySlots(unsigned int inventorySolts);
    /**
     * @brief ill stat of an entity
     * @param nbStat
     */
    void fillStatsSpecs(unsigned int nbStat);
    /**
     * @brief showStatsSpecs
     * @param nbStat
     */
    void showStatsSpecs(unsigned int nbStat);
    /**
     * @fn readJson
     * @brief read an entity from a Qjson array
     * @param json
     */
    virtual void readJson(const QJsonObject &json, const QString & listIterator);
    /**
     * @fn writeJson
     * @brief write an entity inside a Qjson array
     * @param json
     */
    virtual void writeJson(QJsonObject &json, const QString & listIterator) const;
    /**
     * @fn addEntityToArray
     * @brief add an entity to an entity array
     * @param entitiesArray the entity array
     */
    void addEntityToArray(QVector<Entity> & entitiesArray);

private:
    /**
     * @brief type of the entity (for the user to specify)
     * @var typeOfEntity
     * @todo restrict size
     */
    QString type;
    /**
     * @brief Pointer to array of object (Entity inventory)
     * @var inventory
     */
    QVector<Item> inventory;
    /**
     * @brief inventorySlot[0]->used slot,\n inventorySlot[1]->total slot
     * @var inventorySlot[2]
     */
    unsigned int inventoryMaxSlot;
    /**
     * @brief Stats pointer on array of skills
     * @var entitySkills
     */
    QVector<Skill> skills;
};

#endif
