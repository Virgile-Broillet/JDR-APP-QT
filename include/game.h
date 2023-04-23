#ifndef GAME_H
#define GAME_H

#include "world.h"

#include <QVector>
#include <iostream>

class Game
{
public:
    /**
     * @brief constructor of a new Game
     */
    Game();
    /**
     * @brief Destroyer of a Game
     */
    ~Game();
    /**
     * @fn setEntities
     * @brief copy of an entity array to the corresponding array of this object
     * @param entities array to copy
     */
    void setEntities(const QVector<Entity> & entities);
    /**
     * @fn setStatsNames
     * @param setStatsNames
     * @brief copy argument into correspounding class variable
     * @param statsNames
     */
    void setStatsNames(const QVector<QString> & statsNames);
    /**
     * @fn saveGame
     * @brief Save the game, world, object, skills and entity declared inside a file with a name automaticly generated
     * @return true if loading was a success, else false
     */
    bool save();
    /**
     * @fn saveGame
     * @brief Save the game, world, object, skills and entity declared inside a file
     * @param filename name of the file that will contain the save
     * @return true if loading was a success, else false
     */
    bool save(const QString & filename);
    /**
     * @fn loadGame
     * @brief Load the game form a file
     * @param fileName name of the file to load
     * @return true if loading was a success, else false
     */
    bool load(const QString & fileName);
    /**
     * @fn writeJson
     * @brief write a game insite a json array
     * @param[in,out] json array of the game to write
     */
    void writeJson(QJsonObject & json) const;
    /**
     * @fn readJson
     * @brief read a game from a json array
     * @param[in,out] json array of the game to read
     */
    void readJson(const QJsonObject & json);
    /**
     * @fn addNewWorld
     * @brief addNew a new world in game
     * @param worldname
     * @param dimX
     * @param dimY
     * @param texturepath
     */
    void addNewWorld(QString worldname,
                     unsigned int dimX,
                     unsigned int dimY,
                     QString texturepath);
    /**
     * @fn addNewEntity
     * @brief declare a new entity in the game
     * @param[in] name of the entity
     * @param[in] description of the entity
     * @param[in] type of the entity
     * @param[in] texturePath of the entity
     * @param[in] inventoryMaxSlot of the entity
     * @param[in] stats array of the entity
     * @param[in] inventory of the entity
     * @param[in] skills of the entity
     */
    void addNewEntity(const QString name,
                      const QString description,
                      const QString type,
                      const QString texturePath,
                      const unsigned int inventoryMaxSlot,
                      const QVector<Stat> & stats,
                      const QVector<Item> & inventory,
                      const QVector<Skill> & skills);
    /**
     * @fn addNewItem
     * @brief declare a new item in the game
     * @param[in] name of the item
     * @param[in] description of the item
     * @param[in] texturePath of the item
     * @param[in] stats array of the item
     */
    void addNewItem(const QString name,
                    const QString description,
                    const QString texturePath,
                    const QVector<Stat> & stats);
    /**
     * @brief declare a new stat
     * @fn addNewStat
     * @param statName
     */
    void addNewStat(QString statName);
    /**
     * @fn updateStats
     * @brief update all stats of all object, skills and entity, see sheet.h::updateStats()
     */
    void updateStats();
    /**
     * @brief return the QVector<Entity> of the class
     * @return QVector<Entity>
     */
    QVector<Entity> getEntities();
    /**
     * @brief return the QVector<QString> of the class that contains all the names of the stats
     * @return QVector<QStreing>
     */
    QVector<QString> const & getStatsNames();
    /**
     * @brief return the QVector<QString> of the class  but remove the ones that's called "name"
     * @return QVector<QStreing>
     */
    QVector<QString> delStatName(QString name);

private:
    /**
     * @brief List of Stats names declared by the user
     * @var statsNames
     */
    QVector<QString> statsNames;
    /**
     * @brief List of declared world in the game
     * @var worldList
     */
    QVector<World> worlds;
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
