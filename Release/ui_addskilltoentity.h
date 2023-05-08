/********************************************************************************
** Form generated from reading UI file 'addskilltoentity.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSKILLTOENTITY_H
#define UI_ADDSKILLTOENTITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddSkillToEntity
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListView *skillListView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddSkillToEntity)
    {
        if (AddSkillToEntity->objectName().isEmpty())
            AddSkillToEntity->setObjectName("AddSkillToEntity");
        AddSkillToEntity->resize(558, 408);
        verticalLayout_2 = new QVBoxLayout(AddSkillToEntity);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        skillListView = new QListView(AddSkillToEntity);
        skillListView->setObjectName("skillListView");
        skillListView->setSelectionMode(QAbstractItemView::MultiSelection);

        verticalLayout->addWidget(skillListView);

        buttonBox = new QDialogButtonBox(AddSkillToEntity);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AddSkillToEntity);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddSkillToEntity, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddSkillToEntity, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddSkillToEntity);
    } // setupUi

    void retranslateUi(QDialog *AddSkillToEntity)
    {
        AddSkillToEntity->setWindowTitle(QCoreApplication::translate("AddSkillToEntity", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddSkillToEntity: public Ui_AddSkillToEntity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSKILLTOENTITY_H
