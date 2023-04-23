#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../include/game.h"
#include "../include/entity.h"

#include "seesheets.h"
#include "addstatwindow.h"
#include "musicwindow.h"
#include "addentity.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief Construcor of the MainWindow
     * @param[in] parent nullptr
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor of the MainWindow
     */
    ~MainWindow();

private slots:

    /**
     * @fn openMusic
     * @brief open the QDialog of musicWindow
     */
    void openMusic (void);
    /**
     * @fn openEntityWindow
     * @brief open the managing window of entities
     */
    void openEntityWindow (void);
    /**
     * @fn openAddEntity
     * @brief open the QDialog of addEntity
     */
    void openAddEntity (void);
    /**
     * @fn about
     * @brief gives the informations in the Help -> about section
     */
    void about (void);
    /**
     * @fn contact
     * @brief gives the informations in the Help -> contact section
     */
    void contact (void);
    /**
     * @fn addStat
     * @brief open the QDialog of addStatWindow
     */
    void addStat ();
    /**
     * @fn newGame
     * @brief create a new game when clicked on file -> new game
     */
    void newGame (void);
    /**
     * @fn changeBackground
     * @brief change the map background
     */
    void changeBackground();

private:
    /**
     * @brief currentGame used in all the windows of the app
     */
    Game currentGame;
    /**
     * @brief pointer to the ui of MainWindow
     */
    Ui::MainWindow *ui;
    /**
     * @brief pointer to the QDialog (Window) of Music
     */
    MusicWindow * music;
    /**
     * @brief pointer to the QDialog (Window) of seeSheets
     */
    seeSheets * fiche;
    /**
     * @brief pointer to the QDialog (Window) of addEntity
     */
    addEntity * entity;
};

#endif // MAINWINDOW_H
