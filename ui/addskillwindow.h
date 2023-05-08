#ifndef ADDSKILLWINDOW_H
#define ADDSKILLWINDOW_H

#include <QDialog>
#include <QStringListModel>

#include "../include/skill.h"

namespace Ui
{
    class AddSkillWindow;
}

class AddSkillWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Window constructor to declare a new skill
     * @param [in] statsNamesBase the array of declared stats in the game
     * @param parent
     */
    explicit AddSkillWindow(const QVector<QString> & statsNamesBase, QWidget *parent = nullptr);
    /**
     * @brief Window constructor to modify an skill
     * @param [in] statsNamesBase The array of declared stats in the game
     * @param [in] skillBase The skill that will be modified
     * @param parent
     */
    explicit AddSkillWindow(const QVector<QString> & statsNamesBase, Skill * skillBase, QWidget *parent = nullptr);
    ~AddSkillWindow();

private slots:
    /**
     * @fn add
     * @brief Send a skill to the declared list of skill to be added to it
     */
    void add();
    /**
     * @fn modify
     * @brief Modify a skill declared in the list of skill
     */
    void modify();
    /**
     * @fn picture
     * @brief Set the picture filepath of the skill
     */
    void picture();
    /**
     * @fn setMin
     * @brief Set the minimum of the stat currently selected in the combobox
     */
    void setMin();
    /**
     * @fn setValue
     * @brief Set the value of the stat currently selected in the combobox
     */
    void setValue();
    /**
     * @fn setMax
     * @brief Set the maximum of the stat currently selected in the combobox
     */
    void setMax();

signals:
    /**
     * @fn onSkillAdded
     * @brief signal emitted when the add button is pressed
     * @param toAdd The skill that will be added to the game
     */
    void onSkillAdded(Skill & toAdd);

private:
    /**
     * @brief Pointer to the window ui
     * @var ui
     */
    Ui::AddSkillWindow *ui;
    /**
     * @brief model for the combo box of stats names
     * @var statsModel
     */
    QStringListModel * statsModel;
    /**
     * @brief Skill made or modified by the user
     * @var current
     */
    Skill current;
    /**
     * @brief Pointer to the skill that will be modified
     * @var toModify
     */
    Skill * toModify;
    /**
     * @brief Declared stats names
     * @var statsNames
     */
    QVector<QString> statsNames;

    /**
     * @fn populate
     * @brief Populate a list used to make the model of the combo box
     * @param statsNames
     * @return The list of stats names to init the model
     */
    QStringList populate(const QVector<QString> & statsNames);
    /**
     * @fn updateModel
     * @brief update the model for the combo box
     */
    void updateModel();
    /**
     * @fn resetStatsFields
     * @brief reset the stats fiels to the current value of each fields of a skill for the selected stat in the combo box
     */
    void resetStatsFields();
};

#endif // ADDSKILLWINDOW_H
