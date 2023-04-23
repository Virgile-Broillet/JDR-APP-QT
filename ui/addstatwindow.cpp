#include "addstatwindow.h"
#include "QtGui/qevent.h"
#include "ui_addstatwindow.h"
#include <QMessageBox>


addstatwindow::addstatwindow(const QVector<QString> & statsNames, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addstatwindow)
{
    ui->setupUi(this);
    this->save = false;
    this->statsNames = statsNames;
    ui->listWidget->clear();
    ui->listWidget->addItems(statsNames);
    connect(ui->addStat, &QPushButton::clicked, this, &addstatwindow::onAddStatClicked);
    connect(ui->delStat, &QPushButton::clicked, this, &addstatwindow::onDelStatClicked);
}

addstatwindow::~addstatwindow()
{
    delete ui;
}

QVector<QString> addstatwindow::getStatsNames()
{
    return this->statsNames;
}

void addstatwindow::onAddStatClicked()
{
    QString name = ui->name->text();

    if (name.isEmpty())
    {
        QMessageBox::critical(this, tr("Erreur d'ajout"), tr("Il faut obligatoirement un nom a la statistique. \n"), QMessageBox::Ok, QMessageBox::Ok);
        return ;
    }
    else if (this->statsNames.contains(name) == true)
    {
        QMessageBox::critical(this, tr("Erreur d'ajout"), tr("Une statistique existe déjà avec ce nom. \n"), QMessageBox::Ok, QMessageBox::Ok);
        return ;
    }
    else
    {
        this->statsNames.push_back(name);
        this->save = false;
        ui->name->clear();
        ui->listWidget->clear();
        ui->listWidget->addItems(statsNames);
    }
}

void addstatwindow::leaveAndSave()
{
    this->save = true;
    this->oldStats = stats;
    close();
}

void addstatwindow::leave()
{
    int ret;
    ret = QMessageBox::warning(this, tr("Informations"),
                               tr("Toutes les modifications avant sauvegarde seront supprimées \n"
                               "Voulez-vous continuer ?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    switch (ret) {
    case QMessageBox::Yes:
        stats = this->oldStats;;
        ui->listWidget->clear();
        for (int i = 0; i < stats.count(); ++i)
        {
            ui->listWidget->addItem(stats.at(i));
        }
        break;
    case QMessageBox::No:
        return;
        break;
    }

    this->save = true;
    close();
}

void addstatwindow::onDelStatClicked()
{
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        this->statsNames.removeAt(ui->listWidget->currentRow());
        ui->listWidget->clear();
        ui->listWidget->addItems(statsNames);
    }
}

void addstatwindow::closeEvent(QCloseEvent *event)
{
    if (this->save == false)
    {
        int ret;
        ret = QMessageBox::warning(this, tr("Informations"),
                                   tr("Toutes les modifications avant sauvegarde seront supprimées \n"
                                   "Voulez-vous continuer ?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        switch (ret) {
        case QMessageBox::Yes:
            stats = this->oldStats;;
            ui->listWidget->clear();
            for (int i = 0; i < stats.count(); ++i)
            {
                ui->listWidget->addItem(stats.at(i));
            }
            break;
        case QMessageBox::No:
            event->ignore();
            return;
            break;
        }
    }

}


