#include "../include/entity.h"
#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

using namespace std;

Entity::Entity()
{
    this->name = "";
    this->description = "";
    this->inventoryMaxSlot = 0;
}
Entity::Entity(const Entity & entity)
{
    this->name = entity.name;
    this->description = entity.description;
    this->inventoryMaxSlot = entity.inventoryMaxSlot;
    this->inventory = entity.inventory;
    this->skills = entity.skills;
    this->texturePath = entity.texturePath;
}
Entity::Entity(const QString & name,
               const QString & description,
               const QString & texturePath,
               const unsigned int inventoryMaxSlot,
               const QVector<Stat> & stats,
               const QVector<Item> & inventory,
               const QVector<Skill> & skills)
    : Sheet::Sheet(name, description, texturePath, stats)
{
    this->inventoryMaxSlot = inventoryMaxSlot;
    this->inventory = inventory;
    this->skills = skills;
}
Entity::~Entity()
{

}
void Entity::addEntityToArray(QVector<Entity> & entitiesArray)
{
    bool existAlready = false;
    for (int i = 0; i < entitiesArray.count(); i++)
        {
           if (entitiesArray.at(i).getName() == this->name)
            {
               existAlready = true;
               qErrnoWarning(errno, "An entity already have this name");
               break;
            }
        }
    if ((!existAlready) && (!this->name.isEmpty()))
      {
        entitiesArray.push_back(*this);
      }
}
QVector<Item> Entity::getInventory()const
{
    return this->inventory;
}
void Entity::setInventory(const QVector<Item> & newInventory)
{
    this->inventory = newInventory;
}
void Entity::addToInventory(const Item & item)
{
    if (this->inventory.count() < this->inventoryMaxSlot) //if number of item in inventory < max slot
    {
        this->inventory.push_back(item);
    }
}
void Entity::updateInventorySize(const unsigned int size)
{
    if (size < this->inventory.count())
    {
        for (unsigned int i = size; i < this->inventory.count(); ++i)
        {
            this->inventory.pop_back(); //delete last items if there is more than permitted by the new size
        }
    }
    this->inventoryMaxSlot = size; //new inventory size
}
unsigned int Entity::getInventorySlots() const
{
    return this->inventoryMaxSlot;
}
void Entity::addSkill(const Skill & skill)
{
    this->skills.push_back(skill);
}
QVector<Skill> Entity::getSkills() const
{
    return this->skills;
}
void Entity::setSkills(const QVector<Skill> & newSkills)
{
    this->skills = newSkills;
}
void Entity::writeJson(QJsonObject &json, const QString & listIterator) const
{
    this->Sheet::writeJson(json, listIterator);
    QString inventoryMaxSlotKey = "inventoryMaxSlot" + listIterator;
    QString texturePathKey = "texturePath" + listIterator;
    QString nbItemKey = "itemNb" + listIterator;
    QString nbSkillKey = "skillNb" + listIterator;
    json[nbItemKey] = this->inventory.count();
    json[nbSkillKey] = this->skills.count();
    json[inventoryMaxSlotKey] = (int)this->inventoryMaxSlot;
    json[texturePathKey] = this->texturePath;

    unsigned int i;
    unsigned int j;
    for (i = 0; i < this->inventory.count(); i++)
    {
        this->inventory.at(i).writeJson(json, listIterator + QString::number(i));
    }
    for (j = 0; j < this->skills.count(); j++)
    {
        this->skills.at(j).writeJson(json, listIterator + QString::number(j +i+1));
    }
}
void Entity::readJson(const QJsonObject &json, const QString & listIterator)
{
    this->Sheet::readJson(json, listIterator);
    QString inventoryMaxSlotKey = "inventoryMaxSlot" + listIterator;
    QString texturePathKey = "texturePath" + listIterator;
    QString nbItemKey = "itemNb" + listIterator;
    QString nbSkillKey = "skillNb" + listIterator;
    unsigned int nbItem = json[nbItemKey].toInt();
    unsigned int nbSkill = json[nbSkillKey].toInt();
    if (json.contains(inventoryMaxSlotKey) && json[inventoryMaxSlotKey].isString())
    {
        this->inventoryMaxSlot = json[inventoryMaxSlotKey].toInt();
    }
    if (json.contains(texturePathKey) && json[texturePathKey].isString())
    {
        this->texturePath = json[texturePathKey].toString();
    }

    unsigned int i;
    unsigned int j;
    for (i = 0; i < nbItem; i++)
    {
        Item newItem;
        newItem.readJson(json, listIterator + QString::number(i));
        this->inventory.push_back(newItem);
    }
    for (j = 0; j < nbSkill; j++)
    {
        Skill newSkill;
        newSkill.readJson(json, listIterator + QString::number(j +i+1));
        this->skills.push_back(newSkill);
    }
}









void Entity::fillEntitySpec()
{
    string name, description, type;
    cout << "Quel nom voulez-vous donner a votre entite ? " << endl;
    cin >> name;
    this->name = QString::fromStdString(name);
    cout << "Quelle description voulez-vous donner a "<< name << " ?" << endl;
    cin >> description;
    this->description = QString::fromStdString(description);
    cout << "Quel type voulez-vous donner a "<< name << " ?" << endl;
    cin >> type;
    cout << "Combien de cases d'inventaire doit avoir " << name << " au maximum ?" << endl;
    cin >> this->inventoryMaxSlot;
}
void Entity::showEntitySpec()
{
    string name = this->name.toStdString();
    cout << "Votre entite s appelle " << name << endl;
    cout << "Sa description est : " << endl;
    cout << this->description.toStdString() << endl;
    cout << this->name.toStdString() << " possede " << this->inventoryMaxSlot << " place dans son inventaire" << endl;
}
void Entity::fillStatsSpecs(unsigned int nbStat)
{
    for (unsigned int i = 0 ; i < nbStat ; i++)
    {

        string name; unsigned int min, max, val;
        cout<<"Quel est le nom du stat "<<i+1<<endl;
        cin>>name;
        cout<<"Quel est le maximum de la stat "<<name<<" pour ce personnage ? "<<endl;
        cin>>max;
        cout<<"Quel est le minimum de la stat "<<name<<" pour ce personnage ? "<<endl;
        cin>>min;
        cout<<"Quel est le valeur de la stat "<<name<<" pour ce personnage ? "<<endl;
        cin>>val;
        Stat newStat(QString::fromStdString(name),min,max,val);
        this->stats.push_back(newStat);
    }
}
void Entity::showStatsSpecs(unsigned int nbStat)
{
    for (unsigned int i = 0; i < nbStat; i++)
    {
        cout<<"Le nom de la stat " << i+1 << " est " << this->stats.at(i).getName().toStdString() <<endl;
        cout<<"Le minimum de la stat " << i+1 << " est " << this->stats.at(i).getMin() <<endl;
        cout<<"Le maximum de la stat " << i+1 << " est " << this->stats.at(i).getMax() <<endl;
        cout<<"La valeur de la stat " << i+1 << " est " << this->stats.at(i).getValue() <<endl;
    }
}
