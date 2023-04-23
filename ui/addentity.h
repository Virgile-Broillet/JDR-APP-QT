#ifndef ADDENTITY_H
#define ADDENTITY_H

#include <QDialog>
#include "../include/entity.h"

namespace Ui {
class addEntity;
}

class addEntity : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor of the QDialog addEntity
     * @param[in] parent, main QDialog
     * @param[in, out] entityArray QVector of Entity from entity.h
     */
    explicit addEntity(QVector<Entity> &entityArray, QWidget *parent = nullptr);
    /**
     * @brief Destructor of the QDialog addEntity
     */
    ~addEntity();
    QVector<Entity> getEntities ();

private slots:

    /**
     * @fn addButton
     * @brief on click add the entity with all his informations in QVector<Entity> entities
     */
    void addButton (void);
    /**
     * @fn closeEvent
     * @brief summons the MessageBox when closing the QDialog
     */
    void browseButton (void);



private:
    /**
     * @brief boolean true if stat data were saved, false otherwise
     */
    bool save;
    /**
     * @brief pointer to the ui of addEntity
     */
    Ui::addEntity *ui;
    /**
     * @brief create a QVector <Entity> to work on
     */
    QVector<Entity> & entities;
};

#endif // ADDENTITY_H
