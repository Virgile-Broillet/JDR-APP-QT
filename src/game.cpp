#include "../include/game.h"
#include "../include/world.h"
/*
#include "../include/entity.h"
#include "../include/object.h"
#include "../include/skill.h"
*/
using namespace std;


Game::Game()
{

}
Game::~Game()
{

}

void Game::setEntities(const QVector<Entity> & entities)
{
    this->entities = entities;
}
void Game::setStatsNames(const QVector<QString> & statsNames)
{
    this->statsNames = statsNames;
}
void Game::readJson(const QJsonObject & json)
{
    int entitiesCount;
    int itemsCount;
    int skillsCount;
    int statsCount;
    int worldsCount;
    if (json.contains("entitiesCount") && json["entitiesCount"].isDouble())
    {
        entitiesCount = json["entitiesCount"].toInt();
        for(int i = 0; i < entitiesCount; i++)
        {
            Entity temp;
            temp.Entity::readJson(json, QString::number(i));
            entities.push_back(temp);
        }
    }
    if (json.contains("entitiesCount") && json["entitiesCount"].isDouble())
    {
        itemsCount = json["itemsCount"].toInt();
        for(int i = 0; i < itemsCount; i++)
        {
            Item temp;
            temp.Item::readJson(json, QString::number(i));
            items.push_back(temp);
        }
    }
    if (json.contains("skillsCount") && json["skillsCount"].isDouble())
    {
        skillsCount = json["skillsCount"].toInt();
        for(int i = 0; i < skillsCount; i++)
        {
            Skill temp;
            temp.Skill::readJson(json, QString::number(i));
            skills.push_back(temp);
        }
    }
    if (json.contains("entitiesCount") && json["entitiesCount"].isDouble())
    {
        statsCount = json["statsCount"].toInt();
        for(int i = 0; i < statsCount; i++)
        {
            QString keyName= &"statName" [i]; //concat statname and i in one string
            json[keyName] = this->statsNames.at(i);
        }
    }
    if (json.contains("entitiesCount") && json["entitiesCount"].isDouble())
    {
        worldsCount = json["worldsCount"].toInt();
        for(int i = 0; i < worldsCount; i++)
        {
            //this->worlds.at(i).World::readJson(json, QString::number(i));
        }
    }
}
void Game::writeJson(QJsonObject & json) const
{
    int entitiesCount = this->entities.count();
    int itemsCount = this->items.count();
    int skillsCount = this->skills.count();
    int statsCount = this->statsNames.count();
    int worldsCount = this->worlds.count();
    json["entitiesCount"] = entitiesCount;
    json["itemsCount"] = itemsCount;
    json["skillsCount"] = skillsCount;
    json["statsCount"] = statsCount;
    json["worldsCount"] = worldsCount;

    for(int i = 0; i < entitiesCount; i++)
    {
        this->entities.at(i).Entity::writeJson(json, QString::number(i));
    }
    for(int i = 0; i < itemsCount; i++)
    {
        this->items.at(i).Item::writeJson(json, QString::number(i));
    }
    for(int i = 0; i < skillsCount; i++)
    {
        this->skills.at(i).Skill::writeJson(json, QString::number(i));
    }
    for(int i = 0; i < statsCount; i++)
    {
        QString keyName= "statName" + QString::number(i); //concat statname and i in one string
        json[keyName] = this->statsNames.at(i);
    }
    /*
    for(int i = 0; i < worldsCount; i++)
    {
        this->worlds
    }
    */
}
bool Game::save(const QString & filename)
{
    if (!filename.endsWith(".json")) //file extension must be .json
    {
        qWarning("Wrong file extension.");
        return false;
    }
    //this make the path fixed to data/<classname>/<filename>.json
    QFile saveFile("../data/"
                   + QString(typeid(*this).name())
                   + "/"
                   + filename
                   + ".json");
    if (!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning("Couldn't open save file.");
        return false;
    }
    QJsonObject json;
    this->Game::writeJson(json);
    saveFile.write(QJsonDocument(json).toJson());
    saveFile.close();
    return true;
}
bool Game::save()
{
    //generate a name for the save file -> name + current date
    QString filename = "game"
            + QDateTime::currentDateTimeUtc().toString("dd_MM_yyyy");
    return save(filename);
}
bool Game::load(const QString & filename)
{
    if (!filename.endsWith(".json")) //file extension must be .json
    {
        qWarning("Wrong file extension.");
        return false;
    }
    //this make the path fixed to data/<classname>/<filename>
    QFile loadFile("../data/"
                   + QString(typeid(*this).name())
                   + "/"
                   + filename);
    if (!loadFile.open(QIODevice::ReadOnly))
    {
        qWarning("Couldn't open save file.");
        return false;
    }
    QByteArray saveData = loadFile.readAll();
    QJsonObject json = QJsonDocument::fromJson(saveData).object();
    this->readJson(json);
    loadFile.close();
    return true;
}

void Game::addNewWorld(QString worldName,
                       unsigned int dimX,
                       unsigned int dimY,
                       QString texturePath)
{
    World* world = new World(worldName, dimX, dimY, texturePath);
    this->worlds.push_back(*world);
}

void Game::addNewEntity(const QString name,
                        const QString description,
                        const QString type,
                        const QString texturePath,
                        const unsigned int inventoryMaxSlot,
                        const QVector<Stat> & stats,
                        const QVector<Item> & inventory,
                        const QVector<Skill> & skills)
{
    this->entities.push_back(Entity(name, description, type, texturePath, inventoryMaxSlot, stats, inventory, skills));
}
void Game::addNewItem(const QString name,
                      const QString description,
                      const QString texturePath,
                      const QVector<Stat> & stats)
{
    this->items.push_back(Item(name, description, texturePath, stats));
}

void Game::addNewStat(QString statName)
{
    if(this->statsNames.count() > 0)
    {
        cout << statsNames.at(0).toStdString() <<endl;
    }
    if (this->statsNames.contains(statName) == false)
    {
        this->statsNames.push_back(statName);
    }
}

void Game::updateStats()
{
    for(unsigned int i = 0; i < this->entities.count(); i++)
    {
        entities[i].updateStats(this->statsNames);
    }
    for(unsigned int i = 0; i < this->items.count(); i++)
    {
        items[i].updateStats(this->statsNames);
    }
    for(unsigned int i = 0; i < this->skills.count(); i++)
    {
        skills[i].updateStats(this->statsNames);
    }
}

QVector<Entity> Game::getEntities()
{
    return this->entities;
}

QVector<QString> const & Game::getStatsNames()
{
    return this->statsNames;
}

QVector<QString> Game::delStatName(QString name)
{
    for (unsigned int i = 0; i < this->statsNames.count(); i++)
    {
        if (statsNames[i] == name)
        {
            statsNames[i].remove(name);
        }
    }
}

