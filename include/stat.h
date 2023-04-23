#ifndef STAT_H
#define STAT_H

#include <QString>

class Stat
{
public:
    /**
     * @brief Empty constructor of class
     */
    Stat();
    /**
     * @brief Class constructor
     * @param min value of the stat
     * @param max value of the stat
     * @param value of the stat
     */
    Stat(QString name, int min, int max, int value);
    /**
     * @brief Class constructor
     * @param name of the stat
     */
    Stat(QString name);
    ~Stat();
    /**
     * @fn getMin
     * @brief get minimum of the stat
     * @return minimum of the stat
     */
    int getMin()const;
    /**
     * @fn getMax
     * @brief get maximum of the stat
     * @return maximum of the stat
     */
    int getMax()const;
    /**
     * @fn getValue
     * @brief get value of the stat
     * @return value of the stat
     */
    int getValue()const;
    /**
     * @fn getName
     * @brief get the name of a stat
     * @return name of the stats
     */
    QString getName()const;
    /**
     * @fn getIconPath
     * @brief get the icon path of the stat
     * @return the icon path of the stat
     */
    QString getIconPath()const;
    /**
     * @fn setMin
     * @brief set minimum value of the stat
     * @param[in] minimum of stat
     */
    void setMin(const int min);
    /**
     * @fn setMax
     * @brief set maximum value of the stat
     * @param[in] maximum of stat
     */
    void setMax(const int max);
    /**
     * @fn setValue
     * @brief set value of the stat
     * @param[in] value of the stat
     */
    void setValue(const int val);
    /**
     * @fn setName
     * @brief set name of the stat
     * @param[in] name of the stat
     */
    void setName(const QString name);
    /**
     * @fn setIconPath
     * @brief set the icon path of the stat
     * @param[in] filepath
     */
    void setIconPath(const QString filepath);
    /**
     * @brief return if the parameter is the same as the name of the stat
     * @param[in] name
     * @return if the name in parameter is the same as the name of the stat
     */
    bool operator==(const QString name) const;

private:
    /**
     * @brief minimum of the stat
     * @var min
     */
    int min;
    /**
     * @brief value of the stat
     * @var val
     */
    int val;
    /**
     * @brief maximum of the stat
     * @var max
     */
    int max;
    /**
     * @brief Filepath of the icon if the stat
     * @var iconPath
     */
    QString iconPath;
    /**
     * @brief Name of the stat
     * @var name
     */
    QString name;
};

#endif
