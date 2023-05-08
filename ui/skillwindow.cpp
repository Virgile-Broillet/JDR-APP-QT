#include "skillwindow.h"
#include "ui_skillwindow.h"
#include "addskillwindow.h"

#include <QFileDialog>

SkillWindow::SkillWindow(const QVector<QString> statsNamesBase, const QVector<Skill> & skillsBase ,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SkillWindow)
{
    ui->setupUi(this);
    this->skills = skillsBase;
    this->statsNames = statsNamesBase;

    model = new QStringListModel();
    this->updateModel();

    connect(ui->addPushButton, &QPushButton::clicked, this, &SkillWindow::add);
    connect(ui->deletePushButton, &QPushButton::clicked, this, &SkillWindow::remove);
    connect(ui->loadPushButton, &QPushButton::clicked, this, &SkillWindow::load);
    connect(ui->savePushButton, &QPushButton::clicked, this, &SkillWindow::save);
    connect(ui->modifyPushButton, &QPushButton::clicked, this, &SkillWindow::modify);
}

SkillWindow::~SkillWindow()
{
    delete model;
    delete ui;
}

void SkillWindow::updateModel()
{
    QStringList list = populate(this->skills);
    model->setStringList(list);
    ui->skillListView->setModel(model);
}
QVector<Skill> SkillWindow::getSkills(void)
{
    return this->skills;
}
QStringList SkillWindow::populate(const QVector<Skill> & skills)
{
    QStringList list;
    for(int i = 0; i < skills.count(); ++i)
    {
        list << skills.at(i).getName();
    }
    return list;
}
void SkillWindow::add()
{
    AddSkillWindow * win = new AddSkillWindow(this->statsNames);
    connect(win, &AddSkillWindow::onSkillAdded, this, &SkillWindow::addNewSkill);
    win->exec();
    this->updateModel();
    disconnect(win, &AddSkillWindow::onSkillAdded, this, &SkillWindow::addNewSkill);
    delete win;
}
void SkillWindow::modify()
{
    int index = ui->skillListView->currentIndex().row();
    if(index > -1)
    {
        AddSkillWindow * win = new AddSkillWindow(this->statsNames, &this->skills[index]);
        win->exec();
        this->updateModel();
        delete win;
    }
}
void SkillWindow::remove()
{
    int index = ui->skillListView->currentIndex().row();
    if(index > -1)
    {
        this->skills.removeAt(index);
        this->updateModel();
    }
}
void SkillWindow::addNewSkill(Skill & toAdd)
{
    toAdd.addSkillToArray(this->skills);
}
void SkillWindow::load()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Charger un item"), "data/saves",
                                                      tr("JSON (*.json)"));
    Skill s;
    if(s.load(filePath))
    {
        s.addSkillToArray(this->skills);
        this->updateModel();
    }
}
void SkillWindow::save()
{
    int index = ui->skillListView->currentIndex().row();
    if((model->rowCount() > 0) && (index >= 0))
    {
        Skill toSave = skills.at(index);
         QString baseFilePath = "data/saves/"
                 + QString(typeid(toSave).name())
                 + "_"
                 + toSave.getName()
                 + "_"
                 + QDateTime::currentDateTimeUtc().toString("yyyy_MM_dd")
                 + ".json";
        QString filePath = QFileDialog::getSaveFileName(this, tr("Sauvegarder une entité"), baseFilePath,
                                                          tr("JSON (*.json)"));
        toSave.save(filePath);
    }
}
