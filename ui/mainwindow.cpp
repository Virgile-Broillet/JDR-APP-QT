#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "../include/game.h"
#include "addstatwindow.h"
#include "../include/entity.h"
#include "entitywindow.h"
#include <QDir>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    music(new MusicWindow),
    fiche(new seeSheets(parent, this->currentGame.getEntities()))
{
    //create directories for data
    if(!QDir("data").exists())
    {
        QDir().mkdir("data");
    }
    if(!QDir("data/saves").exists())
    {
        QDir().mkdir("data/saves");
    }
    if(!QDir("data/img").exists())
    {
        QDir().mkdir("data/img");
    }

    ui->setupUi(this);
    connect(ui->musicButton, &QPushButton::clicked,this,&MainWindow::openMusic);
    connect(ui->entityWindowButton, &QPushButton::clicked,this,&MainWindow::openEntityWindow);
    connect(ui->newEntityButton, &QPushButton::clicked,this,&MainWindow::openAddEntity);

    connect(ui->actionQuitter, &QAction::triggered, this, & MainWindow::close);
    connect(ui->actionA_propos, &QAction::triggered, this, & MainWindow::about);
    connect(ui->actionContact, &QAction::triggered, this, & MainWindow::contact);
    connect(ui->actionNouvelle_partie, &QAction::triggered, this, & MainWindow::newGame);
    connect(ui->statButton, &QPushButton::clicked, this, & MainWindow::addStat);

    connect(ui->backgroundButton, &QPushButton::clicked, this, & MainWindow::changeBackground);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newGame (void)
{
    Game *second = new Game;
}

void MainWindow::openMusic (void)
{
    music->open();
}

void MainWindow::openAddEntity (void)
{
    entity->open();
}
void MainWindow::openEntityWindow (void)
{
    EntityWindow * win = new EntityWindow(this->currentGame.getEntities(), this);
    int res = win->exec();
    if (res == QDialog::Accepted)
    {
        currentGame.setEntities(win->getEntities());
    }
    delete win;
}
void MainWindow::addStat()
{
    addstatwindow * win = new addstatwindow(this->currentGame.getStatsNames(), this);
    int res = win->exec();
    if (res == QDialog::Accepted)
    {
        currentGame.setStatsNames(win->getStatsNames());
    }
    delete win;
}
void MainWindow::changeBackground()
{
    QString filePath = QFileDialog::getOpenFileName( this, tr("Sauvegarder une entité"),"",
                                                      tr("JPEG PNG BMP IMG (*.jpg *.jpeg *.png *.bmp *.img)" ));
    QPixmap pic;
    pic.load(filePath);
    ui->mapDisplay->setPixmap(pic.scaled(ui->mapDisplay->width(),ui->mapDisplay->height(),Qt::KeepAspectRatio));
}
void MainWindow::about (void)
{
    QMessageBox::information(this,"A propos", "Cette application est utile pour un Maitre du Jeu, elle lui servira a gerer un jeu de role.");
}
void MainWindow::contact (void)
{
    QMessageBox::information(this,"Contact", "DEBAUCHE Ithier p2107886 et BROILLET Virgile p2103804");
}

