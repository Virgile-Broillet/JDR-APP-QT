#include "../include/sheet.h"
#include <iostream>

Sheet::Sheet(){}
Sheet::Sheet(const QString name,
             const QString description,
             const QString texturePath,
             const QVector<Stat> & stats)
{
    this->name = name;
    this->description = description;
    this->texturePath = texturePath;
    this->stats = stats;
}
Sheet::~Sheet(){}

QString Sheet::getName()const
{
    return this->name;
}
void Sheet::setName(const QString name)
{
    this->name = name;
}
QString Sheet::getDescription()const
{
    return this->description;
}
void Sheet::setDescription(const QString description)
{
    this->description = description;
}
QString Sheet::getTexturePath()const
{
    return this->texturePath;
}
void Sheet::setTexturePath(const QString texturePath)
{
    this->texturePath = texturePath;
}

void Sheet::updateStats(const QVector<QString> & statsNames)
{
    for (unsigned int i = 0; i < this->stats.count(); i++)
    {
        //if a stat exist in the list of stats but not in the list of names -> remove it from the list of stat
        if (statsNames.contains(this->stats.at(i).getName()) == false)
        {
            this->stats.removeAt(i);
        }
    }
    for (unsigned int i = 0; i < statsNames.count(); i++)
    {
        //if a stat exist in the list of names but not in the list of stats -> add it to the list of stat
        if (this->stats.contains(statsNames.at(i)) == false)
        {
            const Stat stat(statsNames.at(i));
            this->stats.push_back(stat);
        }
    }
}

void Sheet::writeJson(QJsonObject &json, const QString & listIterator) const
{
    QString nameKey = "name" + listIterator;
    QString descriptionKey = "description" + listIterator;
    QString texturePathKey = "texturePath" + listIterator;
    QString statsNumberKey = "statsNumber" + listIterator;
    json[nameKey] = this->name;
    json[descriptionKey] = this->description;
    json[texturePathKey] = this->texturePath;
    json[statsNumberKey] = this->stats.count();

    for (int i = 0; i < this->stats.count(); i++)
    {
        //key declaration for every stat
        QString iterator = QString::number(i);
        QString nameKey = this->name + "statName" + iterator + listIterator;
        QString minKey = this->name + "statMin" + iterator + listIterator;
        QString maxKey = this->name + "statMax" + iterator + listIterator;
        QString valKey = this->name + "statVal" + iterator + listIterator;
        QString iconKey = this->name + "statIcon" + iterator + listIterator;

        json[nameKey] = this->stats.at(i).getName();
        json[minKey] = this->stats.at(i).getMin();
        json[maxKey] = this->stats.at(i).getMax();
        json[valKey] = this->stats.at(i).getValue();
        json[iconKey] = this->stats.at(i).getIconPath();
    }
}
void Sheet::readJson(const QJsonObject &json, const QString & listIterator)
{
    QString nameKey = "name" + listIterator;
    QString descriptionKey = "description" + listIterator;
    QString texturePathKey = "texturePath" + listIterator;
    QString statsNumberKey = "statsNumber" + listIterator;
    if (json.contains(nameKey) && json[nameKey].isString())
    {
        this->name = json[nameKey].toString();
    }
    if (json.contains(descriptionKey) && json[descriptionKey].isString())
    {
        this->description = json[descriptionKey].toString();
    }
    if (json.contains(texturePathKey) && json[texturePathKey].isString())
    {
        this->texturePath = json[texturePathKey].toString();
    }
    int statNumberjson = 0;
    if (json.contains(statsNumberKey) && json[statsNumberKey].isDouble())
    {
        statNumberjson = json[statsNumberKey].toInt();
    }

    for (int i = 0; i < statNumberjson; i++)
    {
        //key reconstruction
        QString iterator = QString::number(i);
        QString keyName = this->name + "statName" + iterator + listIterator;
        QString keyMin = this->name + "statMin" + iterator + listIterator;
        QString keyMax = this->name + "statMax" + iterator + listIterator;
        QString keyVal = this->name + "statVal" + iterator + listIterator;
        QString keyIcon = this->name + "statIcon" + iterator + listIterator;

        Stat newStat;
        if (json.contains(keyName) && json[keyName].isString())
        {
            newStat.setName(json[keyName].toString());
        }
        if (json.contains(keyMin) && json[keyMin].isDouble())
        {
            newStat.setMin(json[keyMin].toInt());
        }
        if (json.contains(keyMax) && json[keyMax].isDouble())
        {
            newStat.setMax(json[keyMax].toInt());
        }
        if (json.contains(keyVal) && json[keyVal].isDouble())
        {
            newStat.setValue(json[keyVal].toInt());
        }
        if (json.contains(keyIcon) && json[keyIcon].isString())
        {
            newStat.setIconPath(json[keyIcon].toString());
        }
        this->stats.push_back(newStat);
    }
}
bool Sheet::save(QString & filename)
{
    if (!filename.endsWith(".json")) //file extension must be .json
    {
        qWarning("Wrong file extension.");
        return false;
    }
    QFile saveFile(filename);
    if (!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning("Couldn't open save file.");
        return false;
    }
    QJsonObject json;
    this->writeJson(json, "000");
    saveFile.write(QJsonDocument(json).toJson());
    saveFile.close();
    return true;
}
bool Sheet::save()
{
    //generate a name for the save file -> name + current date
    QString filename = this->name
                     + "_"
                     + QDateTime::currentDateTimeUtc().toString("dd_MM_yyyy")
                     + ".json";
    return save(filename);
}
bool Sheet::load(const QString & filePath)
{
    if (!filePath.endsWith(".json")) //file extension must be .json
    {
        qWarning("Wrong file extension.");
        return false;
    }
    //this make the path fixed to data/<classname>_<filename>
    QFile loadFile(filePath);
    if (!loadFile.open(QIODevice::ReadOnly))
    {
        qWarning("Couldn't open save file.");
        return false;
    }
    QByteArray saveData = loadFile.readAll();
    QJsonObject json = QJsonDocument::fromJson(saveData).object();
    this->readJson(json, "000");
    loadFile.close();
    return true;
}
