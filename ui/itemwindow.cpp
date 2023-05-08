#include "itemwindow.h"
#include "ui_itemwindow.h"
#include "additemwindow.h"

#include <QFileDialog>

ItemWindow::ItemWindow(const QVector<QString> &statsNamesBase, const QVector<Item> & itemsBase , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemWindow)
{
    ui->setupUi(this);
    this->items = itemsBase;
    this->statsNames = statsNamesBase;

    model = new QStringListModel();
    this->updateModel();

    connect(ui->addPushButton, &QPushButton::clicked, this, &ItemWindow::add);
    connect(ui->deletePushButton, &QPushButton::clicked, this, &ItemWindow::remove);
    connect(ui->loadPushButton, &QPushButton::clicked, this, &ItemWindow::load);
    connect(ui->savePushButton, &QPushButton::clicked, this, &ItemWindow::save);
    connect(ui->modifyPushButton, &QPushButton::clicked, this, &ItemWindow::modify);
}

ItemWindow::~ItemWindow()
{
    delete model;
    delete ui;
}

void ItemWindow::updateModel()
{
    QStringList list = populate(this->items);
    model->setStringList(list);
    ui->itemListView->setModel(model);
}
QVector<Item> ItemWindow::getItems(void)
{
    return this->items;
}
QStringList ItemWindow::populate(const QVector<Item> & items)
{
    QStringList list;
    for(int i = 0; i < items.count(); ++i)
    {
        list << items.at(i).getName();
    }
    return list;
}
void ItemWindow::add()
{
    AddItemWindow * win = new AddItemWindow(this->statsNames);
    connect(win, &AddItemWindow::onItemAdded, this, &ItemWindow::addNewItem);
    win->exec();
    this->updateModel();
    disconnect(win, &AddItemWindow::onItemAdded, this, &ItemWindow::addNewItem);
    delete win;
}
void ItemWindow::modify()
{
    int index = ui->itemListView->currentIndex().row();
    if(index > -1)
    {
        AddItemWindow * win = new AddItemWindow(this->statsNames, &this->items[index]);
        win->exec();
        this->updateModel();
        delete win;
    }
}
void ItemWindow::remove()
{
    int index = ui->itemListView->currentIndex().row();
    if(index > -1)
    {
        items.removeAt(index);
        this->updateModel();
    }
}
void ItemWindow::addNewItem(Item & toAdd)
{
    toAdd.addItemToArray(this->items);
}
void ItemWindow::load()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Charger un item"), "data/saves",
                                                      tr("JSON (*.json)"));
    Item i;
    if(i.load(filePath))
    {
        i.addItemToArray(this->items);
        this->updateModel();
    }
}
void ItemWindow::save()
{
    int index = ui->itemListView->currentIndex().row();
    if((model->rowCount() > 0) && (index >= 0))
    {
        Item toSave = items.at(index);
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
