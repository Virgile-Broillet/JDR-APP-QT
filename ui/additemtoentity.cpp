#include "additemtoentity.h"
#include "ui_additemtoentity.h"

AddItemToEntity::AddItemToEntity(const QVector<Item> & itemsBase, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItemToEntity),
    model(new QStringListModel())
{
    ui->setupUi(this);
    this->items = itemsBase;
    this->model->setStringList(populate(items));
    ui->itemListView->setModel(this->model);
}
AddItemToEntity::~AddItemToEntity()
{
    delete this->model;
    delete ui;
}

QStringList AddItemToEntity::populate(const QVector<Item> & items)
{
    QStringList list;
    for(int i = 0; i < items.count(); ++i)
    {
        list << items.at(i).getName();
    }
    return list;
}
QVector<Item> AddItemToEntity::getItems()
{
    QVector<Item> selectedItems;
    QModelIndexList iterator(ui->itemListView->selectionModel()->selectedIndexes());
    for(int i = 0; i < iterator.count(); ++i)
    {
        Item item = this->items.at(iterator.at(i).row());
        selectedItems.push_back(item);
    }
    return selectedItems;
}
