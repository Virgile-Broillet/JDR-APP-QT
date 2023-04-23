#include "seesheets.h"
#include "ui_seesheets.h"
#include <QImage>
#include "../include/game.h"



seeSheets::seeSheets(QWidget *parent, const QVector<Entity> & entityArray) :
    QDialog(parent),
    ui(new Ui::seeSheets),
    entities(entityArray)
{
    ui->setupUi(this);
}

seeSheets::~seeSheets()
{
    delete ui;
}
