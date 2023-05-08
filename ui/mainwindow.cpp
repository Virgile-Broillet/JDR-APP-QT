#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

#include "addstatwindow.h"
#include "entitywindow.h"
#include "itemwindow.h"
#include "skillwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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

    connect(ui->statButton, &QPushButton::clicked, this, & MainWindow::openStatWindow);
    connect(ui->entityWindowButton, &QPushButton::clicked,this,&MainWindow::openEntityWindow);
    connect(ui->itemWindowButton, &QPushButton::clicked,this,&MainWindow::openItemWindow);
    connect(ui->skillWindowButton, &QPushButton::clicked,this,&MainWindow::openSkillWindow);


    connect(ui->actionQuitter, &QAction::triggered, this, & MainWindow::close);
    connect(ui->actionA_propos, &QAction::triggered, this, & MainWindow::about);
    connect(ui->actionContact, &QAction::triggered, this, & MainWindow::contact);
    connect(ui->actionNouvelle_partie, &QAction::triggered, this, & MainWindow::newGame);
    connect(ui->actionCharger_une_partie, &QAction::triggered, this, & MainWindow::load);
    connect(ui->actionEnregistrer_la_partie, &QAction::triggered, this, & MainWindow::save);


    connect(ui->backgroundButton, &QPushButton::clicked, this, & MainWindow::changeBackground);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newGame (void)
{
    ///@todo modal window to ask if the user want to save before creating a new save
    ui->mapDisplay->clear();
    this->currentGame = Game();
}
void MainWindow::save()
{
    QString baseFilePath = "data/saves/"
            + QString(typeid(this->currentGame).name())
            + "_"
            + QDateTime::currentDateTimeUtc().toString("yyyy_MM_dd")
            + ".json";
   QString filePath = QFileDialog::getSaveFileName(this, tr("Sauvegarder une partie"), baseFilePath,
                                                     tr("JSON (*.json)"));
   this->currentGame.save(filePath);
}
void MainWindow::load()
{
    ///@todo modal window to ask if the user want to save before loading the save
    QString filePath = QFileDialog::getOpenFileName(this, tr("Charger une partie"), "data/saves",
                                                      tr("JSON (*.json)"));
    newGame();
    currentGame.load(filePath);
    this->loadBackground(this->currentGame.getWorldTexturePath());
}
void MainWindow::openEntityWindow (void)
{
    EntityWindow * win = new EntityWindow(this->currentGame.getStatsNames(),
                                          this->currentGame.getEntities(),
                                          this->currentGame.getItems(),
                                          this->currentGame.getSkills(),
                                          this);
    int res = win->exec();
    if (res == QDialog::Accepted)
    {
        currentGame.setEntities(win->getEntities());
    }
    delete win;
}
void MainWindow::openItemWindow()
{
    ItemWindow * win = new ItemWindow(this->currentGame.getStatsNames(), this->currentGame.getItems(), this);
    int res = win->exec();
    if (res == QDialog::Accepted)
    {
        currentGame.setItems(win->getItems());
    }
    delete win;
}
void MainWindow::openSkillWindow()
{
    SkillWindow * win = new SkillWindow(this->currentGame.getStatsNames(), this->currentGame.getSkills(), this);
    int res = win->exec();
    if (res == QDialog::Accepted)
    {
        currentGame.setSkills(win->getSkills());
    }
    delete win;
}
void MainWindow::openStatWindow()
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
    QString filePath = QFileDialog::getOpenFileName( this, tr("Sauvegarder une entité"),"data/img",
                                                      tr("JPEG PNG BMP IMG (*.jpg *.jpeg *.png *.bmp *.img)" ));
    currentGame.setWorldTexturePath(filePath);
    loadBackground(filePath);
}
void MainWindow::loadBackground(QString filePath)
{
    if(filePath.endsWith(".jpg") ||
       filePath.endsWith(".jpeg") ||
       filePath.endsWith(".png") ||
       filePath.endsWith(".bmp") ||
       filePath.endsWith(".img"))
    {
        QPixmap pic;
        pic.load(filePath);
        ui->mapDisplay->setPixmap(pic.scaled(ui->mapDisplay->width(),ui->mapDisplay->height(),Qt::KeepAspectRatio));
    }
    else
    {
        qErrnoWarning(errno, "Wrong file extension (background load).");
    }
}
void MainWindow::about()
{
    QMessageBox::information(this,"A propos", "Cette application est utile pour un Maitre du Jeu, elle lui servira a gerer un jeu de role.");
}
void MainWindow::contact()
{
    QMessageBox::information(this,"Contact", "DEBAUCHE Ithier p2107886 et BROILLET Virgile p2103804");
}
