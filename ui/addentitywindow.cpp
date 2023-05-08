#include "addentitywindow.h"
#include "ui_addentitywindow.h"
#include "additemtoentity.h"
#include "addskilltoentity.h"

#include <QFileDialog>

AddEntityWindow::AddEntityWindow(const QVector<QString> & statsNamesBase,
                                 const QVector<Item> & itemsBase,
                                 const QVector<Skill> & skillsBase,
                                 QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEntityWindow),
    inventoryModel(new QStringListModel),
    skillsModel(new QStringListModel)
{
    ui->setupUi(this);
    this->statsNames = statsNamesBase;
    this->current.updateStats(statsNamesBase);
    this->items = itemsBase;
    this->skills = skillsBase;
    this->statsModel = new QStringListModel();
    if(statsNamesBase.count() > 0)
    {
        this->statsModel->setStringList(populate(statsNamesBase));
        ui->statNameComboBox->setModel(this->statsModel);
    }

    connect(ui->addButton, &QPushButton::clicked, this, &AddEntityWindow::add);
    connect(ui->picButton, &QPushButton::clicked, this, &AddEntityWindow::picture);
    connect(ui->minField, &QSpinBox::valueChanged, this, &AddEntityWindow::setMin);
    connect(ui->valueField, &QSpinBox::valueChanged, this, &AddEntityWindow::setValue);
    connect(ui->maxField, &QSpinBox::valueChanged, this, &AddEntityWindow::setMax);
    connect(ui->statNameComboBox, &QComboBox::currentIndexChanged, this, &AddEntityWindow::resetStatsFields);
    connect(ui->inventorySlotsSpinBox, &QSpinBox::valueChanged, this, &AddEntityWindow::setInventorySlots);
    connect(ui->addItemButton, &QPushButton::clicked, this, &AddEntityWindow::addToItemsInventory);
    connect(ui->removeItemButton, &QPushButton::clicked, this, &AddEntityWindow::removeFromItemsInventory);
    connect(ui->addSkillButton, &QPushButton::clicked, this, &AddEntityWindow::addToSkillsInventory);
    connect(ui->removeSkillButton, &QPushButton::clicked, this, &AddEntityWindow::removeFromSkillsInventory);
}

AddEntityWindow::AddEntityWindow(const QVector<QString> & statsNamesBase,
                                 const QVector<Item> & itemsBase,
                                 const QVector<Skill> & skillsBase,
                                 Entity * EntityBase, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEntityWindow),
    statsModel(new QStringListModel),
    inventoryModel(new QStringListModel),
    skillsModel(new QStringListModel)
{
    ui->setupUi(this);

    this->items = itemsBase;
    this->skills = skillsBase;

    this->toModify = EntityBase; //keep the pointer to the entity to replace it with the copy
    this->current = *EntityBase; //copy of the entity
    this->current.updateStats(statsNamesBase);

    //ui update
    if(statsNamesBase.count() > 0)
    {
        this->statsModel->setStringList(populate(statsNamesBase));
        ui->statNameComboBox->setModel(this->statsModel);
    }
    ui->nameField->setText(this->current.getName());
    ui->descriptionField->setPlainText(this->current.getDescription());
    ui->inventorySlotsSpinBox->setValue(this->current.getInventorySlots());
    this->resetStatsFields();
    this->updateInventoryModel();
    this->updateSkillsModel();
    QPixmap pic;
    pic.load(this->current.getTexturePath());
    ui->picDisplay->setPixmap(pic.scaled(ui->picDisplay->width(),ui->picDisplay->height(),Qt::KeepAspectRatio));
    ui->addButton->setText("Appliquer");

    //signals
    connect(ui->addButton, &QPushButton::clicked, this, &AddEntityWindow::modify);
    connect(ui->picButton, &QPushButton::clicked, this, &AddEntityWindow::picture);
    connect(ui->minField, &QSpinBox::valueChanged, this, &AddEntityWindow::setMin);
    connect(ui->valueField, &QSpinBox::valueChanged, this, &AddEntityWindow::setValue);
    connect(ui->maxField, &QSpinBox::valueChanged, this, &AddEntityWindow::setMax);
    connect(ui->statNameComboBox, &QComboBox::currentIndexChanged, this, &AddEntityWindow::resetStatsFields);
    connect(ui->inventorySlotsSpinBox, &QSpinBox::valueChanged, this, &AddEntityWindow::setInventorySlots);
    connect(ui->addItemButton, &QPushButton::clicked, this, &AddEntityWindow::addToItemsInventory);
    connect(ui->removeItemButton, &QPushButton::clicked, this, &AddEntityWindow::removeFromItemsInventory);
    connect(ui->addSkillButton, &QPushButton::clicked, this, &AddEntityWindow::addToSkillsInventory);
    connect(ui->removeSkillButton, &QPushButton::clicked, this, &AddEntityWindow::removeFromSkillsInventory);
}
AddEntityWindow::~AddEntityWindow()
{
    delete this->statsModel;
    delete this->inventoryModel;
    delete this->skillsModel;
    delete ui;
}

void AddEntityWindow::setMin()
{
    if(ui->statNameComboBox->currentIndex() > -1)
    {
        int index = ui->statNameComboBox->currentIndex();
        QString statName = this->statsModel->stringList().at(index);
        for(int i = 0; i < this->current.getStatsAdress().count(); ++i)
        {
            if(this->current.getStatsAdress().at(i).getName() == statName)
            {
                this->current.getStatsAdress()[i].setMin(ui->minField->value());
            }
        }
    }
}
void AddEntityWindow::setValue()
{
    if(ui->statNameComboBox->currentIndex() > -1)
    {
        int index = ui->statNameComboBox->currentIndex();
        QString statName = this->statsModel->stringList().at(index);
        for(int i = 0; i < this->current.getStatsAdress().count(); ++i)
        {
            if(this->current.getStatsAdress().at(i).getName() == statName)
            {
                this->current.getStatsAdress()[i].setValue(ui->valueField->value());
            }
        }
    }
}
void AddEntityWindow::setMax()
{
    if(ui->statNameComboBox->currentIndex() > -1)
    {
        int index = ui->statNameComboBox->currentIndex();
        QString statName = this->statsModel->stringList().at(index);
        for(int i = 0; i < this->current.getStatsAdress().count(); ++i)
        {
            if(this->current.getStatsAdress().at(i).getName() == statName)
            {
                this->current.getStatsAdress()[i].setMax(ui->maxField->value());
            }
        }
    }
}
void AddEntityWindow::setInventorySlots()
{
    this->current.updateInventorySize(ui->inventorySlotsSpinBox->value());
    this->updateInventoryModel();
}
void AddEntityWindow::modify()
{
    this->current.setName(ui->nameField->text());
    this->current.setDescription(ui->descriptionField->toPlainText());

    *this->toModify = this->current;
}

void AddEntityWindow::add()
{
    //add item to array
    this->current.setName(ui->nameField->text());
    this->current.setDescription(ui->descriptionField->toPlainText());
    emit onEntityAdded(this->current);

    //ui update
    ui->nameField->clear();
    ui->descriptionField->clear();
    ui->picDisplay->clear();
    ui->inventorySlotsSpinBox->setValue(0);
    ui->statNameComboBox->setCurrentIndex(0); //first slot is selected
    this->current = Entity(); //reset the current entity
    this->current.updateStats(this->statsNames);
    resetStatsFields();

    //model update
    delete this->inventoryModel;
    this->inventoryModel = new QStringListModel;
    delete this->skillsModel;
    this->skillsModel = new QStringListModel;
}
void AddEntityWindow::addToItemsInventory()
{
    AddItemToEntity * win = new AddItemToEntity(this->items);
    int res = win->exec();
    if(res == QDialog::Accepted)
    {
        QVector<Item> toAdd = win->getItems();
        for(int i = 0; i < toAdd.count(); ++i)
        {
            this->current.addToInventory(toAdd.at(i));
        }
    }
    this->updateInventoryModel();
    delete win;
}
void AddEntityWindow::removeFromItemsInventory()
{
    int index = ui->inventoryView->currentIndex().row();
    if(index > -1)
    {
        QVector<Item> newInventory = this->current.getInventory();
        newInventory.removeAt(index);
        this->current.setInventory(newInventory);
        this->updateInventoryModel();
    }
}
void AddEntityWindow::addToSkillsInventory()
{
    AddSkillToEntity * win = new AddSkillToEntity(this->skills);
    int res = win->exec();
    if(res == QDialog::Accepted)
    {
        QVector<Skill> toAdd = win->getSkills();
        for(int i = 0; i < toAdd.count(); ++i)
        {
            this->current.addSkill(toAdd.at(i));
        }
    }
    this->updateSkillsModel();
    delete win;
}
void AddEntityWindow::removeFromSkillsInventory()
{
    int index = ui->skillsView->currentIndex().row();
    if(index > -1)
    {
        QVector<Skill> newSkills = this->current.getSkills();
        newSkills.removeAt(index);
        this->current.setSkills(newSkills);
        this->updateSkillsModel();
    }
}
void AddEntityWindow::picture()
{
    QString filePath = QFileDialog::getOpenFileName( this, tr("Sauvegarder une entité"),"data/img",
                                                      tr("JPEG PNG BMP IMG (*.jpg *.jpeg *.png *.bmp *.img)" ));
    this->current.setTexturePath(filePath);
    QPixmap pic;
    pic.load(filePath);
    ui->picDisplay->setPixmap(pic.scaled(ui->picDisplay->width(),ui->picDisplay->height(),Qt::KeepAspectRatio));
}
QStringList AddEntityWindow::populate(const QVector<QString> & statsNames)
{
    QStringList list;
    for(int i = 0; i < statsNames.count(); ++i)
    {
        list << statsNames.at(i);
    }
    return list;
}
void AddEntityWindow::resetStatsFields()
{
    int min = 0;
    int value = 0;
    int max = 0;
    QVector<Stat> stats = this->current.getStats();
    int index = ui->statNameComboBox->currentIndex();
    if(index > -1)
    {
        QString statName = this->statsModel->stringList().at(index);
        for(int i = 0; i < stats.count(); ++i)
        {
            if(this->current.getStats().at(i).getName() == statName)
            {
                min = stats.at(i).getMin();
                value = stats.at(i).getValue();
                max = stats.at(i).getMax();
                break;
            }
        }
    }
    ui->minField->setValue(min);
    ui->valueField->setValue(value);
    ui->maxField->setValue(max);
}
void AddEntityWindow::updateInventoryModel()
{
    QStringList list;
    for(int i = 0; i < this->current.getInventory().count(); ++i)
    {
        list << this->current.getInventory().at(i).getName();
    }
    this->inventoryModel->setStringList(list);
    ui->inventoryView->setModel(this->inventoryModel);
}
void AddEntityWindow::updateSkillsModel()
{
    QStringList list;
    for(int i = 0; i < this->current.getSkills().count(); ++i)
    {
        list << this->current.getSkills().at(i).getName();
    }
    this->skillsModel->setStringList(list);
    ui->skillsView->setModel(this->skillsModel);
}
