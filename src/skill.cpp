#include "../include/skill.h"


Skill::Skill() : Sheet::Sheet(){}
Skill::Skill(const QString name,
             const QString description,
             const QString texturePath,
             const QVector<Stat> & stats)
    : Sheet::Sheet(name, description, texturePath, stats){}
Skill::~Skill(){}
