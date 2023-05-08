#ifndef SKILLWINDOW_H
#define SKILLWINDOW_H

#include <QDialog>
#include <QWidget>
#include <QStringListModel>

#include "../include/skill.h"

namespace Ui
{
    class SkillWindow;
}

class SkillWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Window constructor to manage skills
     * @param [in] statsNamesBase Array of declared stats names
     * @param [in] skills Array of declared skills
     * @param parent
     */
    explicit SkillWindow(const QVector<QString> statsNamesBase, const QVector<Skill> & skills, QWidget *parent = nullptr);
    ~SkillWindow();

    /**
     * @fn getSkills
     * @brief Get the skill array
     * @return The array of skills modified by the user in the interface
     */
    QVector<Skill>getSkills();

private slots:
    /**
     * @fn add
     * @brief add a new skill and update the model
     */
    void add();
    /**
     * @fn modify
     * @brief modify the selected skill
     */
    void modify();
    /**
     * @fn remove
     * @brief remove the selected skill
     */
    void remove();
    /**
     * @fn load
     * @brief open the file explorer to load a previously saved skill in the current game
     */
    void load();
    /**
     * @fn save
     * @brief open the file explorer to save the selected skill
     */
    void save();
    /**
     * @fn addNewSkill
     * @brief add a new skill to the declared list of skill in the game
     * @param toAdd The skill that will be added
     */
    void addNewSkill(Skill & toAdd);

private:
    /**
     * @brief Pointer to the window ui
     * @var ui
     */
    Ui::SkillWindow *ui;
    /**
     * @brief Array of skills
     * @var skills
     */
    QVector<Skill> skills;
    /**
     * @brief Array of stats names
     * @var statsNames
     */
    QVector<QString> statsNames;
    /**
     * @brief Pointer to the model to display existing skills
     * @var model
     */
    QStringListModel *model;
    /**
     * @fn populate
     * @brief Add all the names of the skills to an array used to make the model
     * @param entities The entity array to be displayed
     * @return a QString list of all the items' names
     */
    QStringList populate(const QVector<Skill> & entities);
    /**
     * @fn updateModel
     * @brief update the listView after adding, removing, or changing the items
     */
    void updateModel();
};

#endif // SKILLWINDOW_H
