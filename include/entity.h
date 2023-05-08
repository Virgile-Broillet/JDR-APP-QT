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
    /**
     * @brief Entity class empty constructor
     */
    Entity();
    /**
     * @brief Entity copy constructor
     * @param [in] entity to copy
     */
    Entity(const Entity & entity);
    /**
     * @brief Entity constructor with complete initialization
     * @param [in] name of an entity
     * @param [in] description of an entity
     * @param [in] texturePath of an entity
     * @param [in] inventoryMaxSlot of an entity
     * @param [in] stats to add to the new entity
     * @param [in] inventory to add to the new entity
     * @param [in] skills to add to the new entity
     */
    Entity(const QString & name,
           const QString & description,
           const QString & texturePath,
           const unsigned int inventoryMaxSlot,
           const QVector<Stat> & stats,
           const QVector<Item> & inventory,
           const QVector<Skill> & skills);
    ~Entity();

    /**
     @fn getInventory
     @brief Get the inventory of the entity
     @returns The entity's inventory in the form of an array
     */
    QVector<Item> getInventory()const;
    /**
     * @fn setInventory
     * @brief Replace the entity's inventory
     * @param [in] newInventory The new inventory
     */
    void setInventory(const QVector<Item> & newInventory);
    /**
     @fn addToInventory
     @brief Add an item to the the entity's inventory
     @param [in] item The item that will be added to the entity's inventory
     */
    void addToInventory(const Item & item);
    /**
     * @fn updateInventorySize
     * @brief Resize the inventory, if there is more item than the targeted size, they will be lost
     * @param [in] size The targeted inventory size
     */
    void updateInventorySize(const unsigned int size);
    /**
     * @fn getInventorySlots
     * @brief Get the number of inventory slot an entity have
     * @return The number of inventory slot an entity have
     */
    unsigned int getInventorySlots()const;
    /**
     * @fn addSkill
     * @brief Add a skill to an entity
     * @param [in] skill The skill that will be added to the entity
     */
    void addSkill(const Skill & skill);
    /**
     * @fn getSkills
     * @brief Get the array of skill possessed by the entity
     * @return The array of skill possessed by the entity
     */
    QVector<Skill> getSkills() const;
    /**
     * @fn setSkills
     * @brief Replace the entity's skills
     * @param newSkills The new skills
     */
    void setSkills(const QVector<Skill> & newSkills);
    /**
     * @fn showEntitySpec
     * @brief (LEGACY) Show all the specs of an entity in the terminal
     */
    void showEntitySpec();
    /**
     * @fn fillEntitySpec
     * @brief (LEGACY) Used to enter all the parameters of a new entity in the terminal
     */
    void fillEntitySpec();
    /**
     * @fn fillStatsSpecs
     * @brief (LEGACY) Fill stats of an entity in the terminal
     * @param[in] nbStat The number of stats
     */
    void fillStatsSpecs(unsigned int nbStat);
    /**
     * @fn showStatsSpecs
     * @brief (LEGACY) Show all the stats of an entity in the terminal
     * @param[in] nbStat
     */
    void showStatsSpecs(unsigned int nbStat);
    /**
     * @fn readJson
     * @brief Read an entity from a buffer
     * @param [in, out] json array to read data
     * @param [in] listIterator Must be the same used to save the entity
     */
    virtual void readJson(const QJsonObject & json, const QString & listIterator);
    /**
     * @fn writeJson
     * @brief Write an entity inside a buffer
     * @param [in, out] json array to write data
     * @param [in] listIterator Must be different for 2 entity saved in the same json
     */
    virtual void writeJson(QJsonObject &json, const QString & listIterator) const;
    /**
     * @fn addEntityToArray
     * @brief Add an entity to an entity array
     * @param [in] entitiesArray The entity array where the entity will be added
     */
    void addEntityToArray(QVector<Entity> & entitiesArray);

private:
    /**
     * @brief Entity inventory
     * @var inventory
     */
    QVector<Item> inventory;
    /**
     * @brief Number of slots in the entity inventory
     * @var inventoryMaxSlot
     */
    unsigned int inventoryMaxSlot;
    /**
     * @brief All skill that the entity have
     * @var skills
     */
    QVector<Skill> skills;
};

#endif
