/********************************************************************************
** Form generated from reading UI file 'skillwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKILLWINDOW_H
#define UI_SKILLWINDOW_H

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

class Ui_SkillWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QListView *skillListView;
    QVBoxLayout *verticalLayout;
    QPushButton *addPushButton;
    QPushButton *modifyPushButton;
    QPushButton *deletePushButton;
    QPushButton *savePushButton;
    QPushButton *loadPushButton;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SkillWindow)
    {
        if (SkillWindow->objectName().isEmpty())
            SkillWindow->setObjectName("SkillWindow");
        SkillWindow->resize(687, 464);
        verticalLayout_3 = new QVBoxLayout(SkillWindow);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        skillListView = new QListView(SkillWindow);
        skillListView->setObjectName("skillListView");
        skillListView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        horizontalLayout->addWidget(skillListView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        addPushButton = new QPushButton(SkillWindow);
        addPushButton->setObjectName("addPushButton");

        verticalLayout->addWidget(addPushButton);

        modifyPushButton = new QPushButton(SkillWindow);
        modifyPushButton->setObjectName("modifyPushButton");

        verticalLayout->addWidget(modifyPushButton);

        deletePushButton = new QPushButton(SkillWindow);
        deletePushButton->setObjectName("deletePushButton");

        verticalLayout->addWidget(deletePushButton);

        savePushButton = new QPushButton(SkillWindow);
        savePushButton->setObjectName("savePushButton");

        verticalLayout->addWidget(savePushButton);

        loadPushButton = new QPushButton(SkillWindow);
        loadPushButton->setObjectName("loadPushButton");

        verticalLayout->addWidget(loadPushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(SkillWindow);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::SaveAll);

        verticalLayout_2->addWidget(buttonBox);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(SkillWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, SkillWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, SkillWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(SkillWindow);
    } // setupUi

    void retranslateUi(QDialog *SkillWindow)
    {
        SkillWindow->setWindowTitle(QCoreApplication::translate("SkillWindow", "Dialog", nullptr));
        addPushButton->setText(QCoreApplication::translate("SkillWindow", "Ajouter", nullptr));
        modifyPushButton->setText(QCoreApplication::translate("SkillWindow", "Modifier", nullptr));
        deletePushButton->setText(QCoreApplication::translate("SkillWindow", "Supprimer", nullptr));
        savePushButton->setText(QCoreApplication::translate("SkillWindow", "Sauvegarder", nullptr));
        loadPushButton->setText(QCoreApplication::translate("SkillWindow", "Charger", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SkillWindow: public Ui_SkillWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKILLWINDOW_H
