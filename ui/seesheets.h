#ifndef SEESHEETS_H
#define SEESHEETS_H
#include "../include/entity.h"

#include <QDialog>

namespace Ui {
class seeSheets;
}

class seeSheets : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construcor of the seeSheets
     * @param[in] parent, main QDialog
     */
    explicit seeSheets(QWidget *parent, const QVector<Entity> & entityArray);
    /**
     * @brief Destructor of the SeeSheets
     */
    ~seeSheets();

private:
    /**
     * @brief pointer to the ui of seeSheets
     */
    Ui::seeSheets *ui;
    /**
     * @brief create a QVector <Entity> to work on
     */
    QVector<Entity> entities;
};

#endif // SEESHEETS_H
