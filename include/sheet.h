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
    /**
     * @brief Sheet class empty constructor
     */
    Sheet();
    /**
     * @brief Sheet class initialized constructor
     * @param [in] name of the sheet
     * @param [in] description of the sheet
     * @param [in] texturePath of the sheet
     * @param [in] stats array of the sheet
     */
    Sheet(const QString & name,
          const QString & description,
          const QString & texturePath,
          const QVector<Stat> & stats);
    virtual ~Sheet();

    /**
     * @fn getName
     * @brief Get the name of the sheet
     * @return The name of the sheet
     */
    QString getName() const;
    /**
     * @fn setName
     * @brief Set the name of the sheet
     * @param [in] name The name of the sheet
     */
    void setName(const QString & name);
    /**
     * @fn getDescription
     * @brief Get hte description of the sheet
     * @return The description of the sheet
     */
    QString getDescription()const;
    /**
     * @fn setDescription
     * @brief Set the description of the sheet
     * @param [in] description The description of the sheet
     */
    void setDescription(const QString description);
    /**
     * @fn getTexturePath
     * @brief Get the texture path to the picture of the sheet
     * @return the texture path of the picture of the sheet
     */
    QString getTexturePath()const;
    /**
     * @fn setTexturePath
     * @brief Set the texture path to the picture of the sheet
     * @param [in] texturePath The full path to the picture
     */
    void setTexturePath(const QString texturePath);
    /**
     * @fn getStats
     * @brief Get the stat array of the sheet
     * @return The stat array of the sheet
     */
    QList<Stat> getStats()const;
    /**
     * @fn updateStats
     * @brief Update the list of stat to only contain all declared stats
     * @param [in] statsNames The list of stats names declared
     */
    void updateStats(const QVector<QString> & statsNames);
    /**
     * @fn writeJson
     * @brief Write a sheet inside a buffer
     * @param [in, out] json Buffer to write data
     * @param [in] listIterator Must be different for 2 sheets saved in the same json
     */
    virtual void writeJson(QJsonObject & json, const QString & listIterator) const;
    /**
     * @fn readJson
     * @brief Read an entity from a buffer
     * @param [in, out] json Buffer to read data
     * @param [in] listIterator Must be the same used to save the sheet
     */
    virtual void readJson(const QJsonObject & json, const QString & listIterator);
    /**
     * @fn save
     * @brief Save the sheet into a file
     * @param [in] filepath The full path of the save file
     * @return True if saving was succesfull, else false
     */
    bool save(const QString & filepath);
    /**
     * @fn load
     * @brief Load a sheet from a file
     * @param [in] filepath The full path of the save file
     * @return True if loading was succesfull, else false
     */
    bool load(const QString & filepath);
    /**
     * @fn getStatsAdress
     * @brief Get the memory adress of the stat array of the sheet
     * @return The memory adress of the stat array of the sheet
     */
    QVector<Stat> & getStatsAdress();
    /**
     * @fn setStats
     * @brief Replace the stat array of the sheet
     * @param [in] statsBase The replacement
     */
    void setStats(const QVector<Stat> & statsBase);

protected:
    /**
     * @brief The name of the sheet
     * @var name
     */
    QString name;
    /**
     * @brief The description of the sheet
     * @var description
     */
    QString description;
    /**
     * @brief The stat array of the sheet
     * @var stats
     */
    QVector<Stat> stats;
    /**
     * @brief Fullpath to the main picture
     * @var texturePath
     */
    QString texturePath;

};

#endif
