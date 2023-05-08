#ifndef STAT_H
#define STAT_H

#include <QString>

class Stat
{
public:
    /**
     * @brief Stat class empty constructor
     */
    Stat();
    /**
     * @brief Stat class constructor
     * @param name name of the stat
     * @param min value of the stat
     * @param max value of the stat
     * @param value of the stat
     */
    Stat(const QString & name, const int min, const int max, const int value);
    /**
     * @brief Class constructor
     * @param name The name of the stat
     */
    Stat(const QString & name);
    ~Stat();

    /**
     * @fn getMin
     * @brief Get minimum of the stat
     * @return The minimum of the stat
     */
    int getMin()const;
    /**
     * @fn getMax
     * @brief Get the maximum of the stat
     * @return The maximum of the stat
     */
    int getMax()const;
    /**
     * @fn getValue
     * @brief Get the value of the stat
     * @return The value of the stat
     */
    int getValue()const;
    /**
     * @fn getName
     * @brief Get the name of a stat
     * @return The name of the stats
     */
    QString getName()const;
    /**
     * @fn setMin
     * @brief Set the minimum of the stat
     * @param [in] min The minimum of stat
     */
    void setMin(const int min);
    /**
     * @fn setMax
     * @brief Set the maximum of the stat
     * @param [in] max The maximum of stat
     */
    void setMax(const int max);
    /**
     * @fn setValue
     * @brief Set the value of the stat
     * @param [in] val The value of the stat
     */
    void setValue(const int val);
    /**
     * @fn setName
     * @brief Set the name of the stat
     * @param [in] name The name of the stat
     */
    void setName(const QString & name);
    /**
     * @brief return if the parameter is the same as the name of the stat
     * @param[in] name The name to compare with
     * @return return if the name in parameter is the same as the name of the stat
     */
    bool operator==(const QString name) const;

private:
    /**
     * @brief Minimum of the stat
     * @var min
     */
    int min;
    /**
     * @brief Value of the stat
     * @var val
     */
    int val;
    /**
     * @brief Maximum of the stat
     * @var max
     */
    int max;
    /**
     * @brief Name of the stat
     * @var name
     */
    QString name;
};

#endif
