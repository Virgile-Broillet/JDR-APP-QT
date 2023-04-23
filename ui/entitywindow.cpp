#include "entitywindow.h"
#include "ui_entitywindow.h"
#include "addentity.h"
#include <QFileDialog>

EntityWindow::EntityWindow(const QVector<Entity> & entitiesBase, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntityWindow)
{
    ui->setupUi(this);
    this->entities = entitiesBase;

    model = new QStringListModel();
    QStringList list = populate(this->entities);
    model->setStringList(list);
    ui->entityListView->setModel(model);

    connect(ui->addPushButton, &QPushButton::clicked, this, &EntityWindow::addEntityFun);
    connect(ui->deletePushButton, &QPushButton::clicked, this, &EntityWindow::removeEntity);
    connect(ui->loadPushButton, &QPushButton::clicked, this, &EntityWindow::loadEntity);
    connect(ui->savePushButton, &QPushButton::clicked, this, &EntityWindow::saveEntity);
    connect(ui->showPushButton, &QPushButton::clicked, this, &EntityWindow::showEntity);
    connect(ui->modifyPushButton, &QPushButton::clicked, this, &EntityWindow::modifyEntity);
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
QVector<Entity> EntityWindow::getEntities(void)
{
    return this->entities;
}
void EntityWindow::addEntityFun()
{
    addEntity * win = new addEntity(this->entities);
    win->exec();
    updateModel();
}

void EntityWindow::modifyEntity()
{

}
void EntityWindow::removeEntity()
{
    if(model->rowCount() > 0)
    {
        QModelIndex i = ui->entityListView->currentIndex();
        entities.removeAt(i.row());
        updateModel();
    }
}
void EntityWindow::showEntity()
{

}
void EntityWindow::loadEntity()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Charger une entité"), "data/saves",
                                                      tr("JSON (*.json)"));
    Entity e;
    e.load(filePath);
    e.addEntityToArray(this->entities);
    updateModel();
}
void EntityWindow::saveEntity()
{
    if(model->rowCount() > 0)
    {
        QModelIndex i = ui->entityListView->currentIndex();
        Entity toSave = entities.at(i.row());
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
QStringList EntityWindow::populate(const QVector<Entity> & entities)
{
    QStringList list;
    for(int i = 0; i < entities.count(); ++i)
    {
        list << entities.at(i).getName();
    }
    return list;
}
