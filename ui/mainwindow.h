#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../include/game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Window constructor of the main window
     * @param parent
     */
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    /**
     * @fn openEntityWindow
     * @brief Open the window to manage entities
     */
    void openEntityWindow();
    /**
     * @fn openItemWindow
     * @brief Open the window to manage entities items
     */
    void openItemWindow();
    /**
     * @fn openSkillWindow
     * @brief Open the window to manage entities skills
     */
    void openSkillWindow();
    /**
     * @fn about
     * @brief Open the window "about"
     */
    void about();
    /**
     * @fn contact
     * @brief Open the window "contact"
     */
    void contact();
    /**
     * @fn openStatWindow
     * @brief Open the window to manage stats names
     */
    void openStatWindow();
    /**
     * @fn newGame
     * @brief Create a new game
     */
    void newGame();
    /**
     * @fn changeBackground
     * @brief Change the map background
     */
    void changeBackground();
    /**
     * @fn save
     * @brief Save the current game in a Json file
     */
    void save();
    /**
     * @fn load
     * @brief Load a Json file and overwrite the current game with its data
     */
    void load();

private:
    /**
     * @brief The current game
     * @var currentGame
     */
    Game currentGame;
    /**
     * @brief Pointer to the window ui
     * @var ui
     */
    Ui::MainWindow *ui;

    /**
     * @fn loadBackground
     * @brief Display the map texture
     * @param filePath The fullpath of the picture that will be displayed
     */
    void loadBackground(QString filePath);
};

#endif // MAINWINDOW_H
