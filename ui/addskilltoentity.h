#ifndef ADDSKILLTOENTITY_H
#define ADDSKILLTOENTITY_H

#include <QDialog>
#include <QStringListModel>

#include "../include/skill.h"

namespace Ui
{
    class AddSkillToEntity;
}

class AddSkillToEntity : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Window constructor to add declared skills to an entity inventory
     * @param [in] skillsBase The array of declared skills
     * @param parent
     */
    explicit AddSkillToEntity(const QVector<Skill> & skillsBase, QWidget *parent = nullptr);
    ~AddSkillToEntity();

    /**
     * @fn getSkills
     * @brief Get the array of selected skills to add to an entity
     * @return The array of selected skills
     */
    QVector<Skill> getSkills();

private:
    /**
     * @brief The pointer to the window ui
     * @var ui
     */
    Ui::AddSkillToEntity *ui;
    /**
     * @brief Declared skills to be displayed
     * @var skills
     */
    QVector<Skill> skills;
    /**
     * @brief Pointer to the model to display the skills
     * @var model
     */
    QStringListModel * model;

    /**
     * @fn populate
     * @brief Used to make the model to display skills with their names
     * @param skills The item array that will be displayed
     * @return The array of all skills names
     */
    QStringList populate(const QVector<Skill> & skills);
};

#endif // ADDSKILLTOENTITY_H
