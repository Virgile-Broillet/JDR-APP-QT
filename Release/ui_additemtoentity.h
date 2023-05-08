/********************************************************************************
** Form generated from reading UI file 'additemtoentity.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEMTOENTITY_H
#define UI_ADDITEMTOENTITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddItemToEntity
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListView *itemListView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddItemToEntity)
    {
        if (AddItemToEntity->objectName().isEmpty())
            AddItemToEntity->setObjectName("AddItemToEntity");
        AddItemToEntity->resize(558, 408);
        verticalLayout_2 = new QVBoxLayout(AddItemToEntity);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        itemListView = new QListView(AddItemToEntity);
        itemListView->setObjectName("itemListView");
        itemListView->setSelectionMode(QAbstractItemView::MultiSelection);

        verticalLayout->addWidget(itemListView);

        buttonBox = new QDialogButtonBox(AddItemToEntity);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AddItemToEntity);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddItemToEntity, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddItemToEntity, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddItemToEntity);
    } // setupUi

    void retranslateUi(QDialog *AddItemToEntity)
    {
        AddItemToEntity->setWindowTitle(QCoreApplication::translate("AddItemToEntity", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddItemToEntity: public Ui_AddItemToEntity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEMTOENTITY_H
