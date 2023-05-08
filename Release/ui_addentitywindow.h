/********************************************************************************
** Form generated from reading UI file 'addentitywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDENTITYWINDOW_H
#define UI_ADDENTITYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddEntityWindow
{
public:
    QVBoxLayout *verticalLayout_18;
    QVBoxLayout *verticalLayout_16;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *nameField;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QPlainTextEdit *descriptionField;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout;
    QLabel *picDisplay;
    QPushButton *picButton;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QComboBox *statNameComboBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_4;
    QSpinBox *minField;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QSpinBox *valueField;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QSpinBox *maxField;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_9;
    QSpinBox *inventorySlotsSpinBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_7;
    QListView *inventoryView;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addItemButton;
    QPushButton *removeItemButton;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_8;
    QListView *skillsView;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *addSkillButton;
    QPushButton *removeSkillButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddEntityWindow)
    {
        if (AddEntityWindow->objectName().isEmpty())
            AddEntityWindow->setObjectName("AddEntityWindow");
        AddEntityWindow->resize(635, 703);
        verticalLayout_18 = new QVBoxLayout(AddEntityWindow);
        verticalLayout_18->setObjectName("verticalLayout_18");
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName("verticalLayout_16");
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName("verticalLayout_15");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(AddEntityWindow);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        nameField = new QLineEdit(AddEntityWindow);
        nameField->setObjectName("nameField");

        verticalLayout_2->addWidget(nameField);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(AddEntityWindow);
        label_2->setObjectName("label_2");

        verticalLayout_3->addWidget(label_2);

        descriptionField = new QPlainTextEdit(AddEntityWindow);
        descriptionField->setObjectName("descriptionField");

        verticalLayout_3->addWidget(descriptionField);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        picDisplay = new QLabel(AddEntityWindow);
        picDisplay->setObjectName("picDisplay");
        picDisplay->setMinimumSize(QSize(128, 128));
        picDisplay->setMaximumSize(QSize(128, 128));

        verticalLayout->addWidget(picDisplay);

        picButton = new QPushButton(AddEntityWindow);
        picButton->setObjectName("picButton");

        verticalLayout->addWidget(picButton);


        verticalLayout_10->addLayout(verticalLayout);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_3 = new QLabel(AddEntityWindow);
        label_3->setObjectName("label_3");

        verticalLayout_5->addWidget(label_3);

        statNameComboBox = new QComboBox(AddEntityWindow);
        statNameComboBox->setObjectName("statNameComboBox");

        verticalLayout_5->addWidget(statNameComboBox);


        verticalLayout_9->addLayout(verticalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_4 = new QLabel(AddEntityWindow);
        label_4->setObjectName("label_4");

        verticalLayout_8->addWidget(label_4);

        minField = new QSpinBox(AddEntityWindow);
        minField->setObjectName("minField");

        verticalLayout_8->addWidget(minField);


        horizontalLayout->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_5 = new QLabel(AddEntityWindow);
        label_5->setObjectName("label_5");

        verticalLayout_7->addWidget(label_5);

        valueField = new QSpinBox(AddEntityWindow);
        valueField->setObjectName("valueField");

        verticalLayout_7->addWidget(valueField);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_6 = new QLabel(AddEntityWindow);
        label_6->setObjectName("label_6");

        verticalLayout_6->addWidget(label_6);

        maxField = new QSpinBox(AddEntityWindow);
        maxField->setObjectName("maxField");

        verticalLayout_6->addWidget(maxField);


        horizontalLayout->addLayout(verticalLayout_6);


        verticalLayout_9->addLayout(horizontalLayout);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName("verticalLayout_17");
        label_9 = new QLabel(AddEntityWindow);
        label_9->setObjectName("label_9");

        verticalLayout_17->addWidget(label_9);

        inventorySlotsSpinBox = new QSpinBox(AddEntityWindow);
        inventorySlotsSpinBox->setObjectName("inventorySlotsSpinBox");

        verticalLayout_17->addWidget(inventorySlotsSpinBox);


        verticalLayout_9->addLayout(verticalLayout_17);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);


        verticalLayout_10->addLayout(verticalLayout_9);


        horizontalLayout_2->addLayout(verticalLayout_10);


        verticalLayout_15->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        label_7 = new QLabel(AddEntityWindow);
        label_7->setObjectName("label_7");

        verticalLayout_11->addWidget(label_7);

        inventoryView = new QListView(AddEntityWindow);
        inventoryView->setObjectName("inventoryView");

        verticalLayout_11->addWidget(inventoryView);


        verticalLayout_13->addLayout(verticalLayout_11);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        addItemButton = new QPushButton(AddEntityWindow);
        addItemButton->setObjectName("addItemButton");

        horizontalLayout_4->addWidget(addItemButton);

        removeItemButton = new QPushButton(AddEntityWindow);
        removeItemButton->setObjectName("removeItemButton");

        horizontalLayout_4->addWidget(removeItemButton);


        verticalLayout_13->addLayout(horizontalLayout_4);


        horizontalLayout_6->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName("verticalLayout_14");
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        label_8 = new QLabel(AddEntityWindow);
        label_8->setObjectName("label_8");

        verticalLayout_12->addWidget(label_8);

        skillsView = new QListView(AddEntityWindow);
        skillsView->setObjectName("skillsView");

        verticalLayout_12->addWidget(skillsView);


        verticalLayout_14->addLayout(verticalLayout_12);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        addSkillButton = new QPushButton(AddEntityWindow);
        addSkillButton->setObjectName("addSkillButton");

        horizontalLayout_5->addWidget(addSkillButton);

        removeSkillButton = new QPushButton(AddEntityWindow);
        removeSkillButton->setObjectName("removeSkillButton");

        horizontalLayout_5->addWidget(removeSkillButton);


        verticalLayout_14->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_14);


        verticalLayout_15->addLayout(horizontalLayout_6);


        verticalLayout_16->addLayout(verticalLayout_15);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        addButton = new QPushButton(AddEntityWindow);
        addButton->setObjectName("addButton");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(addButton);

        buttonBox = new QDialogButtonBox(AddEntityWindow);
        buttonBox->setObjectName("buttonBox");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        horizontalLayout_3->addWidget(buttonBox);


        verticalLayout_16->addLayout(horizontalLayout_3);


        verticalLayout_18->addLayout(verticalLayout_16);


        retranslateUi(AddEntityWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddEntityWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddEntityWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddEntityWindow);
    } // setupUi

    void retranslateUi(QDialog *AddEntityWindow)
    {
        AddEntityWindow->setWindowTitle(QCoreApplication::translate("AddEntityWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddEntityWindow", "Nom", nullptr));
        label_2->setText(QCoreApplication::translate("AddEntityWindow", "Description", nullptr));
        picDisplay->setText(QString());
        picButton->setText(QCoreApplication::translate("AddEntityWindow", "Ajouter une image...", nullptr));
        label_3->setText(QCoreApplication::translate("AddEntityWindow", "Statistiques", nullptr));
        label_4->setText(QCoreApplication::translate("AddEntityWindow", "Min", nullptr));
        label_5->setText(QCoreApplication::translate("AddEntityWindow", "Value", nullptr));
        label_6->setText(QCoreApplication::translate("AddEntityWindow", "Max", nullptr));
        label_9->setText(QCoreApplication::translate("AddEntityWindow", "Taille d'inventaire", nullptr));
        label_7->setText(QCoreApplication::translate("AddEntityWindow", "Inventaire", nullptr));
        addItemButton->setText(QCoreApplication::translate("AddEntityWindow", "Ajouter", nullptr));
        removeItemButton->setText(QCoreApplication::translate("AddEntityWindow", "Retirer", nullptr));
        label_8->setText(QCoreApplication::translate("AddEntityWindow", "Comp\303\251tences", nullptr));
        addSkillButton->setText(QCoreApplication::translate("AddEntityWindow", "Ajouter", nullptr));
        removeSkillButton->setText(QCoreApplication::translate("AddEntityWindow", "Retirer", nullptr));
        addButton->setText(QCoreApplication::translate("AddEntityWindow", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEntityWindow: public Ui_AddEntityWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDENTITYWINDOW_H
