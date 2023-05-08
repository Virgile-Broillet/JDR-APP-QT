/********************************************************************************
** Form generated from reading UI file 'entitywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTITYWINDOW_H
#define UI_ENTITYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EntityWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QListView *entityListView;
    QVBoxLayout *verticalLayout;
    QPushButton *addPushButton;
    QPushButton *modifyPushButton;
    QPushButton *deletePushButton;
    QPushButton *savePushButton;
    QPushButton *loadPushButton;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EntityWindow)
    {
        if (EntityWindow->objectName().isEmpty())
            EntityWindow->setObjectName("EntityWindow");
        EntityWindow->resize(687, 464);
        verticalLayout_3 = new QVBoxLayout(EntityWindow);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        entityListView = new QListView(EntityWindow);
        entityListView->setObjectName("entityListView");
        entityListView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        horizontalLayout->addWidget(entityListView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        addPushButton = new QPushButton(EntityWindow);
        addPushButton->setObjectName("addPushButton");

        verticalLayout->addWidget(addPushButton);

        modifyPushButton = new QPushButton(EntityWindow);
        modifyPushButton->setObjectName("modifyPushButton");

        verticalLayout->addWidget(modifyPushButton);

        deletePushButton = new QPushButton(EntityWindow);
        deletePushButton->setObjectName("deletePushButton");

        verticalLayout->addWidget(deletePushButton);

        savePushButton = new QPushButton(EntityWindow);
        savePushButton->setObjectName("savePushButton");

        verticalLayout->addWidget(savePushButton);

        loadPushButton = new QPushButton(EntityWindow);
        loadPushButton->setObjectName("loadPushButton");

        verticalLayout->addWidget(loadPushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(EntityWindow);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::SaveAll);

        verticalLayout_2->addWidget(buttonBox);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(EntityWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EntityWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EntityWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EntityWindow);
    } // setupUi

    void retranslateUi(QDialog *EntityWindow)
    {
        EntityWindow->setWindowTitle(QCoreApplication::translate("EntityWindow", "Dialog", nullptr));
        addPushButton->setText(QCoreApplication::translate("EntityWindow", "Ajouter", nullptr));
        modifyPushButton->setText(QCoreApplication::translate("EntityWindow", "Modifier", nullptr));
        deletePushButton->setText(QCoreApplication::translate("EntityWindow", "Supprimer", nullptr));
        savePushButton->setText(QCoreApplication::translate("EntityWindow", "Sauvegarder", nullptr));
        loadPushButton->setText(QCoreApplication::translate("EntityWindow", "Charger", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EntityWindow: public Ui_EntityWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTITYWINDOW_H
