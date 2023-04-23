#include "addentity.h"
#include "ui_addentity.h"
#include <iostream>
#include <QMessageBox>
#include <QFileDialog>
#include <QImage>

#include "../include/entity.h"

addEntity::addEntity(QVector<Entity> & entityArray, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEntity),
    entities(entityArray)
{
    ui->setupUi(this);
    this->save = false;
    connect(ui->addEntityButton,&QPushButton::clicked,this,&addEntity::addButton);
    connect(ui->ImageBrowser, &QPushButton::clicked, this, &addEntity::browseButton);
}

void addEntity::browseButton (void)
{
    QString imagePath = QFileDialog::getOpenFileName( this, tr("Ajouter un fichier"),"",
                                                      tr("JPEG PNG BMP IMG (*.jpg *.jpeg *.png *.bmp *.img)" ));
    QPixmap *pixmap_img = new QPixmap(imagePath);

    ui->Imagelabel->setPixmap(pixmap_img->scaled(ui->Imagelabel->width(),ui->Imagelabel->height(),Qt::KeepAspectRatio));
}


void addEntity::addButton(void)
{
    QString name = ui->Name->text();
    QString Type = ui->Type->text();
    QString Desc = ui->Desc->toPlainText();

    int ret;


    if (Type.isEmpty() || Desc.isEmpty())
    {
        ret = QMessageBox::warning(this, tr("Information d'ajout"), tr("Vous allez ajouter une entité sans type ou sans description. \n"
                                                                 "Voulez-vous continuer ?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        switch (ret) {
        case QMessageBox::Ok:
            break;
        default:
            break;
        }
    }
    Entity current;
    current.setName(name);
    current.setType(Type);
    current.setDescription(Desc);
    current.addEntityToArray(this->entities);

    ///@todo clean l'image, le nb de slot, le tableau des skills
    ui->Desc->clear();
    ui->Name->clear();
    ui->Type->clear();
}


QVector<Entity> addEntity::getEntities ()
{
    return entities;
}

addEntity::~addEntity()
{
    delete ui;
}





