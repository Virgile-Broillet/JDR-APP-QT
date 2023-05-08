#include "addskillwindow.h"
#include "ui_addskillwindow.h"

#include <QFileDialog>

AddSkillWindow::AddSkillWindow(const QVector<QString> & statsNamesBase, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSkillWindow),
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

    connect(ui->addButton, &QPushButton::clicked, this, &AddSkillWindow::add);
    connect(ui->picButton, &QPushButton::clicked, this, &AddSkillWindow::picture);
    connect(ui->minField, &QSpinBox::valueChanged, this, &AddSkillWindow::setMin);
    connect(ui->valueField, &QSpinBox::valueChanged, this, &AddSkillWindow::setValue);
    connect(ui->maxField, &QSpinBox::valueChanged, this, &AddSkillWindow::setMax);
    connect(ui->statNameComboBox, &QComboBox::currentIndexChanged, this, &AddSkillWindow::resetStatsFields);
}

AddSkillWindow::AddSkillWindow(const QVector<QString> & statsNamesBase, Skill * skillBase, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSkillWindow),
    statsModel(new QStringListModel)
{
    ui->setupUi(this);

    this->toModify = skillBase; //keep the pointer to the item to replace it with the copy
    this->current = *skillBase; //copy of the item
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
    connect(ui->addButton, &QPushButton::clicked, this, &AddSkillWindow::modify);
    connect(ui->picButton, &QPushButton::clicked, this, &AddSkillWindow::picture);
    connect(ui->minField, &QSpinBox::valueChanged, this, &AddSkillWindow::setMin);
    connect(ui->valueField, &QSpinBox::valueChanged, this, &AddSkillWindow::setValue);
    connect(ui->maxField, &QSpinBox::valueChanged, this, &AddSkillWindow::setMax);
    connect(ui->statNameComboBox, &QComboBox::currentIndexChanged, this, &AddSkillWindow::resetStatsFields);
}
AddSkillWindow::~AddSkillWindow()
{
    delete this->statsModel;
    delete ui;
}

void AddSkillWindow::setMin()
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
void AddSkillWindow::setValue()
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
void AddSkillWindow::setMax()
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
void AddSkillWindow::modify()
{
    this->current.setName(ui->nameField->text());
    this->current.setDescription(ui->descriptionField->toPlainText());

    *this->toModify = this->current;
}

void AddSkillWindow::add()
{
    //add item to array
    this->current.setName(ui->nameField->text());
    this->current.setDescription(ui->descriptionField->toPlainText());
    emit onSkillAdded(this->current);

    //ui update
    ui->nameField->clear();
    ui->descriptionField->clear();
    ui->picDisplay->clear();
    ui->statNameComboBox->setCurrentIndex(0); //first slot is selected
    this->current = Skill();
    this->current.updateStats(this->statsNames);//reset the current item
    resetStatsFields();
}
void AddSkillWindow::picture()
{
    QString filePath = QFileDialog::getOpenFileName( this, tr("Sauvegarder une entité"),"data/img",
                                                      tr("JPEG PNG BMP IMG (*.jpg *.jpeg *.png *.bmp *.img)" ));
    this->current.setTexturePath(filePath);
    QPixmap pic;
    pic.load(filePath);
    ui->picDisplay->setPixmap(pic.scaled(ui->picDisplay->width(),ui->picDisplay->height(),Qt::KeepAspectRatio));
}
QStringList AddSkillWindow::populate(const QVector<QString> & statsNames)
{
    QStringList list;
    for(int i = 0; i < statsNames.count(); ++i)
    {
        list << statsNames.at(i);
    }
    return list;
}
void AddSkillWindow::resetStatsFields()
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
