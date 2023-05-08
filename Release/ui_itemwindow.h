/********************************************************************************
** Form generated from reading UI file 'itemwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMWINDOW_H
#define UI_ITEMWINDOW_H

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

class Ui_ItemWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QListView *itemListView;
    QVBoxLayout *verticalLayout;
    QPushButton *addPushButton;
    QPushButton *modifyPushButton;
    QPushButton *deletePushButton;
    QPushButton *savePushButton;
    QPushButton *loadPushButton;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ItemWindow)
    {
        if (ItemWindow->objectName().isEmpty())
            ItemWindow->setObjectName("ItemWindow");
        ItemWindow->resize(687, 464);
        verticalLayout_3 = new QVBoxLayout(ItemWindow);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        itemListView = new QListView(ItemWindow);
        itemListView->setObjectName("itemListView");
        itemListView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        horizontalLayout->addWidget(itemListView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        addPushButton = new QPushButton(ItemWindow);
        addPushButton->setObjectName("addPushButton");

        verticalLayout->addWidget(addPushButton);

        modifyPushButton = new QPushButton(ItemWindow);
        modifyPushButton->setObjectName("modifyPushButton");

        verticalLayout->addWidget(modifyPushButton);

        deletePushButton = new QPushButton(ItemWindow);
        deletePushButton->setObjectName("deletePushButton");

        verticalLayout->addWidget(deletePushButton);

        savePushButton = new QPushButton(ItemWindow);
        savePushButton->setObjectName("savePushButton");

        verticalLayout->addWidget(savePushButton);

        loadPushButton = new QPushButton(ItemWindow);
        loadPushButton->setObjectName("loadPushButton");

        verticalLayout->addWidget(loadPushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(ItemWindow);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::SaveAll);

        verticalLayout_2->addWidget(buttonBox);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(ItemWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ItemWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ItemWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ItemWindow);
    } // setupUi

    void retranslateUi(QDialog *ItemWindow)
    {
        ItemWindow->setWindowTitle(QCoreApplication::translate("ItemWindow", "Dialog", nullptr));
        addPushButton->setText(QCoreApplication::translate("ItemWindow", "Ajouter", nullptr));
        modifyPushButton->setText(QCoreApplication::translate("ItemWindow", "Modifier", nullptr));
        deletePushButton->setText(QCoreApplication::translate("ItemWindow", "Supprimer", nullptr));
        savePushButton->setText(QCoreApplication::translate("ItemWindow", "Sauvegarder", nullptr));
        loadPushButton->setText(QCoreApplication::translate("ItemWindow", "Charger", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ItemWindow: public Ui_ItemWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMWINDOW_H
