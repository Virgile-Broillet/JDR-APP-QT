#include "../include/game.h"

using namespace std;


Game::Game()
{

}
Game::~Game()
{

}

QVector<Entity> Game::getEntities() const
{
    return this->entities;
}
void Game::setEntities(const QVector<Entity> & entities)
{
    this->entities = entities;
}
QVector<Item> Game::getItems() const
{
    return this->items;
}
void Game::setItems(const QVector<Item> & items)
{
    this->items = items;
}
QVector<Skill> Game::getSkills() const
{
    return this->skills;
}
void Game::setSkills(const QVector<Skill> & skills)
{
    this->skills = skills;
}
QVector<QString> Game::getStatsNames() const
{
    return this->statsNames;
}
void Game::setStatsNames(const QVector<QString> & statsNames)
{
    this->statsNames = statsNames;
}
void Game::setWorldTexturePath(const QString & filePath)
{
    this->worldTexturePath = filePath;
}
QString Game::getWorldTexturePath() const
{
    return this->worldTexturePath;
}
void Game::readJson(const QJsonObject & json)
{
    int entitiesCount;
    int itemsCount;
    int skillsCount;
    int statsCount;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    if (json.contains("entitiesCount") && json["entitiesCount"].isDouble())
    {
        entitiesCount = json["entitiesCount"].toInt();
        for(a = 0; a < entitiesCount; ++a)
        {
            Entity temp;
            temp.Entity::readJson(json, QString::number(a));
            entities.push_back(temp);
        }
    }
    if (json.contains("itemsCount") && json["itemsCount"].isDouble())
    {
        itemsCount = json["itemsCount"].toInt();
        for(b = 0; b < itemsCount; ++b)
        {
            Item temp;
            temp.Item::readJson(json, QString::number(b +a+1));
            items.push_back(temp);
        }
    }
    if (json.contains("skillsCount") && json["skillsCount"].isDouble())
    {
        skillsCount = json["skillsCount"].toInt();
        for(c = 0; c < skillsCount; ++c)
        {
            Skill temp;
            temp.Skill::readJson(json, QString::number(c +b+a+1));
            skills.push_back(temp);
        }
    }
    if (json.contains("statsCount") && json["statsCount"].isDouble())
    {
        statsCount = json["statsCount"].toInt();
        for(d = 0; d < statsCount; ++d)
        {
            QString keyName= "statName" + QString::number(d +c+b+a+1); //concat statname and i in one string
            this->statsNames.push_back(json[keyName].toString());
        }
    }
    if (json.contains("worldTexturePath") && json["worldTexturePath"].isString())
    {
        this->worldTexturePath = json["worldTexturePath"].toString() ;
    }
}
void Game::writeJson(QJsonObject & json) const
{
    int entitiesCount = this->entities.count();
    int itemsCount = this->items.count();
    int skillsCount = this->skills.count();
    int statsCount = this->statsNames.count();
    QString worldTexturePath = this->worldTexturePath;
    json["entitiesCount"] = entitiesCount;
    json["itemsCount"] = itemsCount;
    json["skillsCount"] = skillsCount;
    json["statsCount"] = statsCount;
    json["worldTexturePath"] = worldTexturePath;
    int a;
    int b;
    int c;
    int d;
    for(a = 0; a < entitiesCount; ++a)
    {
        this->entities.at(a).Entity::writeJson(json, QString::number(a));
    }
    for(b = 0; b < itemsCount; ++b)
    {
        this->items.at(b).Item::writeJson(json, QString::number(b +a+1));
    }
    for(c = 0; c < skillsCount; ++c)
    {
        this->skills.at(c).Skill::writeJson(json, QString::number(c +b+a+1));
    }
    for(d = 0; d < statsCount; ++d)
    {
        QString keyName= "statName" + QString::number(d +c+b+a+1); //concat statname and d in one string
        json[keyName] = this->statsNames.at(d);
    }
}
bool Game::save(const QString & filename)
{
    if (!filename.endsWith(".json")) //file extension must be .json
    {
        qWarning("Wrong file extension (game save).");
        return false;
    }
    QFile saveFile(filename);
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
bool Game::load(const QString & filename)
{
    if (!filename.endsWith(".json")) //file extension must be .json
    {
        qWarning("Wrong file extension (game load).");
        return false;
    }
    QFile loadFile(filename);
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
void Game::addNewEntity(const QString &name,
                        const QString &description,
                        const QString &texturePath,
                        const unsigned int inventoryMaxSlot,
                        const QVector<Stat> & stats,
                        const QVector<Item> & inventory,
                        const QVector<Skill> & skills)
{
    this->entities.push_back(Entity(name, description, texturePath, inventoryMaxSlot, stats, inventory, skills));
}
void Game::addNewItem(const QString &name,
                      const QString &description,
                      const QString &texturePath,
                      const QVector<Stat> & stats)
{
    this->items.push_back(Item(name, description, texturePath, stats));
}

void Game::addNewStat(const QString & statName)
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
