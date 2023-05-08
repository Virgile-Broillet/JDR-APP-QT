#include "entitywindow.h"
#include "ui_entitywindow.h"
#include "addentitywindow.h"

#include <QFileDialog>

EntityWindow::EntityWindow(const QVector<QString> & statsNamesBase,
                           const QVector<Entity> & entitiesBase,
                           const QVector<Item> & itemsBase,
                           const QVector<Skill> & skillsBase,
                           QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntityWindow)
{
    ui->setupUi(this);
    this->entities = entitiesBase;
    this->items = itemsBase;
    this->skills = skillsBase;
    this->statsNames = statsNamesBase;

    model = new QStringListModel();
    this->updateModel();

    connect(ui->addPushButton, &QPushButton::clicked, this, &EntityWindow::add);
    connect(ui->deletePushButton, &QPushButton::clicked, this, &EntityWindow::remove);
    connect(ui->loadPushButton, &QPushButton::clicked, this, &EntityWindow::load);
    connect(ui->savePushButton, &QPushButton::clicked, this, &EntityWindow::save);
    connect(ui->modifyPushButton, &QPushButton::clicked, this, &EntityWindow::modify);
}

EntityWindow::~EntityWindow()
{
    delete model;
    delete ui;
}

void EntityWindow::updateModel()
{
    QStringList list = populate(this->entities);
    model->setStringList(list);
    ui->entityListView->setModel(model);
}
QVector<Entity> EntityWindow::getEntities()
{
    return this->entities;
}
QStringList EntityWindow::populate(const QVector<Entity> & entities)
{
    QStringList list;
    for(int i = 0; i < entities.count(); ++i)
    {
        list << entities.at(i).getName();
    }
    return list;
}
void EntityWindow::add()
{
    AddEntityWindow * win = new AddEntityWindow(this->statsNames, this->items, this->skills);
    connect(win, &AddEntityWindow::onEntityAdded, this, &EntityWindow::addNewEntity);
    win->exec();
    this->updateModel();
    disconnect(win, &AddEntityWindow::onEntityAdded, this, &EntityWindow::addNewEntity);
    delete win;
}
void EntityWindow::modify()
{
    int index = ui->entityListView->currentIndex().row();
    if(index > -1)
    {
        AddEntityWindow * win = new AddEntityWindow(this->statsNames, this->items, this->skills, &this->entities[index]);
        win->exec();
        this->updateModel();
        delete win;
    }
}
void EntityWindow::remove()
{
    int index = ui->entityListView->currentIndex().row();
    if(index > -1)
    {
        entities.removeAt(index);
        this->updateModel();
    }
}
void EntityWindow::addNewEntity(Entity & toAdd)
{
    toAdd.addEntityToArray(this->entities);
}
void EntityWindow::load()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Charger un item"), "data/saves",
                                                      tr("JSON (*.json)"));
    Entity e;
    if(e.load(filePath))
    {
        e.addEntityToArray(this->entities);
        this->updateModel();
    }
}
void EntityWindow::save()
{
    int index = ui->entityListView->currentIndex().row();
    if((model->rowCount() > 0) && (index >= 0))
    {
        Entity toSave = entities.at(index);
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
