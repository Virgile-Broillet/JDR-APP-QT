#ifndef GAME_H
#define GAME_H

#include "../include/item.h"
#include "../include/entity.h"
#include "../include/skill.h"

#include <QVector>
#include <iostream>

class Game
{
public:
    /**
     * @brief Constructor of Game class
     */
    Game();
    ~Game();
    /**
     * @fn getEntities
     * @brief Get all entities declared in the game
     * @return The entity array of the game
     */
    QVector<Entity> getEntities() const;
    /**
     * @fn setEntities
     * @brief Replace the entity array of the game with a new one
     * @param [in] entities The replacement array
     */
    void setEntities(const QVector<Entity> & entities);
    /**
     * @fn getItems
     * @brief Get all items declared in the game
     * @return The item array of the game
     */
    QVector<Item> getItems() const;
    /**
     * @fn setItems
     * @brief Copy of an entity array into the corresponding array of this object
     * @param [in] items The replacement array
     */
    void setItems(const QVector<Item> & items);
    /**
     * @fn getSkills
     * @brief Get all the skills declared in the game
     * @return The skill array of the game
     */
    QVector<Skill> getSkills() const;
    /**
     * @fn setSkills
     * @brief Copy of a skill array into the corresponding array of this object
     * @param [in] skills The replacement array
     */
    void setSkills(const QVector<Skill> & skills);
    /**
     * @fn setStatsNames
     * @brief Copy of a stats names array into the corresponding array of this object
     * @param [in] statsNames The replacement array
     */
    void setStatsNames(const QVector<QString> & statsNames);
    /**
     * @fn save
     * @brief Save the game (and all its objects) inside a new file
     * @param [in] filename The name of the file that will be created to save
     * @return True if saving was successfull, else false
     */
    bool save(const QString & filename);
    /**
     * @fn load
     * @brief Load the game from a file
     * @param [in] fileName The name of the file to load
     * @return True if loading was successfull, else false
     */
    bool load(const QString & fileName);
    /**
     * @fn writeJson
     * @brief Write a game inside a buffer
     * @param [in,out] json Buffer to write the game's data
     */
    void writeJson(QJsonObject & json) const;
    /**
     * @fn readJson
     * @brief Read a game from a buffer
     * @param [in,out] json Buffer to read the game's data
     */
    void readJson(const QJsonObject & json);
    /**
     * @fn addNewEntity
     * @brief Declare a new entity in the game
     * @param [in] name The name of the entity
     * @param [in] description The description of the entity
     * @param [in] texturePath The texturePath of the entity
     * @param [in] inventoryMaxSlot The number of inventory the entity have
     * @param [in] stats The stats array of the entity
     * @param [in] inventory THe inventory of the entity
     * @param [in] skills The array of skills of the entity
     */
    void addNewEntity(const QString & name,
                      const QString & description,
                      const QString & texturePath,
                      const unsigned int inventoryMaxSlot,
                      const QVector<Stat> & stats,
                      const QVector<Item> & inventory,
                      const QVector<Skill> & skills);
    /**
     * @fn addNewItem
     * @brief declare a new item in the game
     * @param [in] name of the item
     * @param [in] description of the item
     * @param [in] texturePath of the item
     * @param [in] stats array of the item
     */
    void addNewItem(const QString & name,
                    const QString & description,
                    const QString & texturePath,
                    const QVector<Stat> & stats);
    /**
     * @fn addNewStat
     * @brief Declare a new stat in the game
     * @param [in] statName The name of the new stat
     */
    void addNewStat(const QString & statName);
    /**
     * @fn updateStats
     * @brief Update all stats of all items, skills and entities
     */
    void updateStats();
    /**
     * @fn getStatsNames
     * @brief Get all stats names declared in games in an array
     * @return The stats names array of the current game
     */
    QVector<QString> getStatsNames() const;
    /**
     * @fn delStatName
     * @brief Remove one stat name from the stats names array
     * @param [in] name The stat to remove
     * @return The base array without the element removed
     */
    QVector<QString> delStatName(const QString & name);
    /**
     * @fn setWorldTexturePath
     * @brief Set the texture path of an image for the map background
     * @param [in] filePath The complete path to the file
     */
    void setWorldTexturePath(const QString & filePath);
    /**
     * @fn getWorldTexturePath
     * @brief Get the current texture path of an image for the map background
     * @return The texture path of the world
     */
    QString getWorldTexturePath()const;

private:
    /**
     * @brief List of Stats names declared int the game
     * @var statsNames
     */
    QVector<QString> statsNames;
    /**
     * @brief Full textur path to the map picture
     * @var worldTexturePath
     */
    QString worldTexturePath;
    /**
     * @brief List of declared entities in the game
     * @var entities
     */
    QVector<Entity> entities;
    /**
     * @brief List of declared items in the game
     * @var items
     */
    QVector<Item> items;
    /**
     * @brief List of declared skills in the game
     * @var skills
     */
    QVector<Skill> skills;

};

#endif
