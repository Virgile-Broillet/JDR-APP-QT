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
     * @brief Constructor of the QDialog addStatWindow
     * @param[in] parent, main QDialog
     * @param[in, out] statsArray Qvecor of String from game.h
     */
    explicit addstatwindow(const QVector<QString> & statsNames, QWidget *parent = nullptr);

    /**
     * @brief Destructor of addStatWindow
     */
    ~addstatwindow();
    /**
     * @fn statsNames
     * @brief
     * @return the new statNames array
     */
    QVector<QString> getStatsNames();

private slots:

    /**
     * @fn onAddStatClicked
     * @brief on click add a stat with all his informations in QVector<QString> stats
     */
    void onAddStatClicked();
    /**
     * @fn onDelStatClicked
     * @brief on click delete the selected stat and all his informations in QVector<QString> stats
     */
    void onDelStatClicked();
    /**
     * @fn leaveAndSave
     * @brief leave and SAVE the stats informations in QVector<QString> stats
     */
    void leaveAndSave();
    /**
     * @fn leave
     * @brief leave WITHOUT saving the stats informations in QVector<QString> stats
     */
    void leave();
    /**
     * @fn closeEvent
     * @brief summons the MessageBox when closing the QDialog
     */
    void closeEvent(QCloseEvent *event);

private:
    /**
     * @brief boolean true if stat data were saved, false otherwise
     */
    bool save;
    /**
     * @brief pointer to the ui of addStatWindow
     */
    Ui::addstatwindow *ui;
    /**
     * @brief create a QVector <QString> to work on
     */
    QVector<QString> stats;
    /**
     * @brief cThe old state of Vector stats without the last save
     */
    QVector<QString> oldStats;
    /**
     * @brief work copy of the main array of stats names
     * @var statsNames
     */
    QVector<QString> statsNames;
};

#endif // ADDSTATWINDOW_H
