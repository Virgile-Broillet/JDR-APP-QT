#include "addskilltoentity.h"
#include "ui_addskilltoentity.h"

AddSkillToEntity::AddSkillToEntity(const QVector<Skill> & skillsBase, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSkillToEntity),
    model(new QStringListModel())
{
    ui->setupUi(this);
    this->skills = skillsBase;
    this->model->setStringList(populate(skills));
    ui->skillListView->setModel(this->model);
}
AddSkillToEntity::~AddSkillToEntity()
{
    delete this->model;
    delete ui;
}

QStringList AddSkillToEntity::populate(const QVector<Skill> & skills)
{
    QStringList list;
    for(int i = 0; i < skills.count(); ++i)
    {
        list << skills.at(i).getName();
    }
    return list;
}
QVector<Skill> AddSkillToEntity::getSkills()
{
    QVector<Skill> selectedItems;
    QModelIndexList iterator(ui->skillListView->selectionModel()->selectedIndexes());
    for(int i = 0; i < iterator.count(); ++i)
    {
        Skill skill = this->skills.at(iterator.at(i).row());
        selectedItems.push_back(skill);
    }
    return selectedItems;
}
