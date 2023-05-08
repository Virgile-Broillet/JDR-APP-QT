#include "../include/skill.h"


Skill::Skill() : Sheet::Sheet(){}
Skill::Skill(const QString &name,
             const QString &description,
             const QString &texturePath,
             const QVector<Stat> & stats)
    : Sheet::Sheet(name, description, texturePath, stats){}
Skill::~Skill(){}
void Skill::addSkillToArray(QVector<Skill> & skillsArray)
{
    bool existAlready = false;
    for (int i = 0; i < skillsArray.count(); i++)
        {
           if (skillsArray.at(i).getName() == this->name)
            {
               existAlready = true;
               qErrnoWarning(errno, "A skill already have this name");
               break;
            }
        }
    if ((!existAlready) && (!this->name.isEmpty()))
      {
        skillsArray.push_back(*this);
      }
}
