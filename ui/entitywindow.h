#ifndef ENTITYWINDOW_H
#define ENTITYWINDOW_H

#include "../include/entity.h"
#include <QDialog>
#include <QWidget>
#include <QStringListModel>
#include "addentity.h"

namespace Ui {
class EntityWindow;
}

class EntityWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EntityWindow(const QVector<Entity> & entities, QWidget *parent = nullptr);
    ~EntityWindow();
    QVector<Entity>getEntities(void);

private slots:
    void addEntityFun();
    void modifyEntity();
    void removeEntity();
    void showEntity();
    void loadEntity();
    void saveEntity();

private:
    Ui::EntityWindow *ui;
    QVector<Entity> entities;
    QStringListModel *model;
    QStringList populate(const QVector<Entity> & entities);
    void updateModel();
};

#endif // ENTITYWINDOW_H
