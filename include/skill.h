#ifndef SKILL_H
#define SKILL_H

#include "../include/sheet.h"

class Skill : public Sheet
{
public:
    /**
     * @brief Skill class empty constructor
     */
    Skill();
    /**
     * @brief Skill class initiliazed constructor
     * @param[in] name The name of the skill
     * @param[in] description The description of the skill
     * @param[in] texturePath The full path to the picture of the skill
     * @param[in] stats The stat array of the skill
     */
    Skill(const QString & name,
          const QString & description,
          const QString & texturePath,
          const QVector<Stat> & stats);
    ~Skill();

    /**
     * @fn addSkillToArray
     * @brief Add the skill to an array
     * @param[in] skillsArray The array where the skill will be added
     */
    void addSkillToArray(QVector<Skill> & skillsArray);
};
#endif
