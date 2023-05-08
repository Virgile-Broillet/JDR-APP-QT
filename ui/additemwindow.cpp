#include "additemwindow.h"
#include "ui_additemwindow.h"

#include <QFileDialog>

AddItemWindow::AddItemWindow(const QVector<QString> & statsNamesBase, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItemWindow),
        statsModel(new QStringListModel)
{
    ui->setupUi(this);
    this->statsNames = statsNamesBase;
    this->current.updateStats(statsNamesBase);
    if(statsNamesBase.count() > 0)
    {
        this->statsModel->setStringList(populate(statsNamesBase));
        ui->statNameComboBox->setModel(this->statsModel);
    }

    connect(ui->addButton, &QPushButton::clicked, this, &AddItemWindow::add);
    connect(ui->picButton, &QPushButton::clicked, this, &AddItemWindow::picture);
    connect(ui->minField, &QSpinBox::valueChanged, this, &AddItemWindow::setMin);
    connect(ui->valueField, &QSpinBox::valueChanged, this, &AddItemWindow::setValue);
    connect(ui->maxField, &QSpinBox::valueChanged, this, &AddItemWindow::setMax);
    connect(ui->statNameComboBox, &QComboBox::currentIndexChanged, this, &AddItemWindow::resetStatsFields);
}

AddItemWindow::AddItemWindow(const QVector<QString> & statsNamesBase, Item * ItemBase, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItemWindow),
    statsModel(new QStringListModel)
{
    ui->setupUi(this);

    this->toModify = ItemBase; //keep the pointer to the item to replace it with the copy
    this->current = *ItemBase; //copy of the item
    this->current.updateStats(statsNamesBase);

    //ui update
    if(statsNamesBase.count() > 0)
    {

        this->statsModel->setStringList(populate(statsNamesBase));
        ui->statNameComboBox->setModel(this->statsModel);
    }
    ui->nameField->setText(this->current.getName());
    ui->descriptionField->setPlainText(this->current.getDescription());
    this->resetStatsFields();
    QPixmap pic;
    pic.load(this->current.getTexturePath());
    ui->picDisplay->setPixmap(pic.scaled(ui->picDisplay->width(),ui->picDisplay->height(),Qt::KeepAspectRatio));
    ui->addButton->setText("Appliquer");

    //signals
    connect(ui->addButton, &QPushButton::clicked, this, &AddItemWindow::modify);
    connect(ui->picButton, &QPushButton::clicked, this, &AddItemWindow::picture);
    connect(ui->minField, &QSpinBox::valueChanged, this, &AddItemWindow::setMin);
    connect(ui->valueField, &QSpinBox::valueChanged, this, &AddItemWindow::setValue);
    connect(ui->maxField, &QSpinBox::valueChanged, this, &AddItemWindow::setMax);
    connect(ui->statNameComboBox, &QComboBox::currentIndexChanged, this, &AddItemWindow::resetStatsFields);
}
AddItemWindow::~AddItemWindow()
{
    delete this->statsModel;
    delete ui;
}

void AddItemWindow::setMin()
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
void AddItemWindow::setValue()
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
void AddItemWindow::setMax()
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
void AddItemWindow::modify()
{
    this->current.setName(ui->nameField->text());
    this->current.setDescription(ui->descriptionField->toPlainText());

    *this->toModify = this->current;
}

void AddItemWindow::add()
{
    //add item to array
    this->current.setName(ui->nameField->text());
    this->current.setDescription(ui->descriptionField->toPlainText());
    emit onItemAdded(this->current);

    //ui update
    ui->nameField->clear();
    ui->descriptionField->clear();
    ui->picDisplay->clear();
    ui->statNameComboBox->setCurrentIndex(0); //first slot is selected
    this->current = Item();
    this->current.updateStats(this->statsNames);//reset the current item
    resetStatsFields();
}
void AddItemWindow::picture()
{
    QString filePath = QFileDialog::getOpenFileName( this, tr("Sauvegarder une entité"),"data/img",
                                                      tr("JPEG PNG BMP IMG (*.jpg *.jpeg *.png *.bmp *.img)" ));
    this->current.setTexturePath(filePath);
    QPixmap pic;
    pic.load(filePath);
    ui->picDisplay->setPixmap(pic.scaled(ui->picDisplay->width(),ui->picDisplay->height(),Qt::KeepAspectRatio));
}
QStringList AddItemWindow::populate(const QVector<QString> & statsNames)
{
    QStringList list;
    for(int i = 0; i < statsNames.count(); ++i)
    {
        list << statsNames.at(i);
    }
    return list;
}
void AddItemWindow::resetStatsFields()
{
    int min = 0;
    int value = 0;
    int max = 0;
    int index = ui->statNameComboBox->currentIndex();
    if(index > -1)
    {
        QString statName = this->statsModel->stringList().at(index);
        for(int i = 0; i < this->current.getStatsAdress().count(); ++i)
        {
            if(this->current.getStatsAdress().at(i).getName() == statName)
            {
                min = current.getStats().at(i).getMin();
                value = current.getStats().at(i).getValue();
                max = current.getStats().at(i).getMax();
                break;
            }
        }
    }
    ui->minField->setValue(min);
    ui->valueField->setValue(value);
    ui->maxField->setValue(max);
}
