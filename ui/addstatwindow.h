#ifndef ADDSTATWINDOW_H
#define ADDSTATWINDOW_H

#include <QDialog>
#include <QWidget>

namespace Ui {
class addstatwindow;
}

class addstatwindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Window constructor to add stats
     * @param[in] statsNames the array of declared stats in the game
     * @param parent
     */
    explicit addstatwindow(const QVector<QString> & statsNames, QWidget *parent = nullptr);
    ~addstatwindow();

    /**
     * @fn statsNames
     * @brief Get the current array of stats names
     * @return The new statNames array
     */
    QVector<QString> getStatsNames();

private slots:

    /**
     * @fn onAddStatClicked
     * @brief Add a stat
     */
    void onAddStatClicked();
    /**
     * @fn onDelStatClicked
     * @brief Delete the selected stat
     */
    void onDelStatClicked();
    /**
     * @fn leaveAndSave
     * @brief Leave and SAVE the stats
     */
    void leaveAndSave();
    /**
     * @fn leave
     * @brief leave WITHOUT saving the stats
     */
    void leave();
    /**
     * @fn closeEvent
     * @brief summons the MessageBox when closing the window
     * @param[in] event Pointer on the event "close the dialog"
     */
    void closeEvent(QCloseEvent *event);

private:
    /**
     * @brief True if stat data were saved, false otherwise
     * @var save
     */
    bool save;
    /**
     * @brief Pointer to the window ui
     * @var ui
     */
    Ui::addstatwindow *ui;
    /**
     * @brief Working array of stat
     * @var stats
     */
    QVector<QString> stats;
    /**
     * @brief cThe old state of Vector stats without the last save
     * @var oldStats
     */
    QVector<QString> oldStats;
    /**
     * @brief work copy of the main array of stats names
     * @var statsNames
     */
    QVector<QString> statsNames;
};

#endif // ADDSTATWINDOW_H
