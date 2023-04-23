#ifndef SHEET_H
#define SHEET_H

#include "../include/stat.h"

#include <QVector>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QIODevice>
#include <QDateTime>

class Sheet
{

public:
    Sheet();
    /**
     * @brief Sheet initialized constructor
     * @param[in] name of the sheet
     * @param[in] description of the sheet
     * @param[in] texturePath of the sheet
     * @param[in] stats array of the sheet
     */
    Sheet(const QString name,
          const QString description,
          const QString texturePath,
          const QVector<Stat> & stats);
    ~Sheet();
    /**
     * @fn getName
     * @brief get the name of the sheet
     * @return the name of the sheet
     */
    QString getName() const;
    /**
     * @fn setName
     * @brief set the name of the sheet
     * @param name of the sheet
     */
    void setName(const QString name);
    /**
     * @fn getDescription
     * @brief get hte description of the sheet
     * @return The description in a QString
     */
    QString getDescription()const;
    /**
     * @fn setDescription
     * @brief set the description of the sheet
     * @param description of the sheet
     */
    void setDescription(const QString description);
    /**
     * @fn getTexturePath
     * @brief get the texture path to the picture of the sheet
     * @return the texture path of the picture of the sheet
     */
    QString getTexturePath()const;
    /**
     * @fn setTexturePath
     * @brief set the texture path to the picture of the sheet
     * @param texturePath of the picture
     */
    void setTexturePath(const QString texturePath);
    /**
     * @fn getStats
     * @brief get stats list
     * @return stat list
     */
    QList<Stat> getStats()const;
    /**
     * @fn updateStats
     * @brief update the list of stat to only constain all declared stats
     * @param statsNames the list of stats names
     */
    void updateStats(const QVector<QString> & statsNames);
    /**
     * @fn writeJson
     * @brief write a sheet insite a json array
     * @param[in,out] json array of the sheet to write
     */
    virtual void writeJson(QJsonObject & json, const QString & listIterator) const;
    /**
     * @fn readJson
     * @brief read a sheet insite a json array
     * @param[in,out] json array of the sheet to read
     */
    virtual void readJson(const QJsonObject & json, const QString & listIterator);
    /**
     * @fn save
     * @brief save a QjsonObject into a file
     * @param filename of the save
     * @return true if succesfull, false if not
     */
    bool save(QString & filename);
    /**
     * @fn save
     * @brief save a QjsonObject into a file with a name automatically generated
     * @return true if succesfull, false if not
     */
    bool save();
    /**
     * @fn load
     * @brief load a sheet from a file
     * @param filename of the name of file to load, not the path
     * @return true if succesfull, false if not
     */
    bool load(const QString &filename);

protected:
    /**
     * @brief name
     * @var name
     * @todo restrict size
     */
    QString name;
    /**
     * @brief description
     * @var description
     */
    QString description;
    /**
     * @brief Stats list
     * @var entityStats
     */
    QVector<Stat> stats;
    /**
     * @brief path of the main picture
     * @var texturePath
     */
    QString texturePath;

};

#endif
