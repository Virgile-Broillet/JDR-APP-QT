#ifndef SKILL_H
#define SKILL_H

#include "../include/sheet.h"

class Skill : public Sheet
{
public:
    /**
     * @brief enpty constructor of Skill class
     */
    Skill();
    /**
     * @brief Initiliazed Skill class constructor
     * @param name of the skill
     * @param description of the skill
     * @param texturePath of the skill
     * @param stats array of the skill
     */
    Skill(const QString name,
          const QString description,
          const QString texturePath,
          const QVector<Stat> & stats);
    /**
     * @brief destructor of Skills
     */
    ~Skill();
};
#endif
