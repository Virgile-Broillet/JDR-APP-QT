/********************************************************************************
** Form generated from reading UI file 'addskillwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSKILLWINDOW_H
#define UI_ADDSKILLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddSkillWindow
{
public:
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_11;
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
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddSkillWindow)
    {
        if (AddSkillWindow->objectName().isEmpty())
            AddSkillWindow->setObjectName("AddSkillWindow");
        AddSkillWindow->resize(536, 417);
        verticalLayout_12 = new QVBoxLayout(AddSkillWindow);
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(AddSkillWindow);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        nameField = new QLineEdit(AddSkillWindow);
        nameField->setObjectName("nameField");

        verticalLayout_2->addWidget(nameField);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(AddSkillWindow);
        label_2->setObjectName("label_2");

        verticalLayout_3->addWidget(label_2);

        descriptionField = new QPlainTextEdit(AddSkillWindow);
        descriptionField->setObjectName("descriptionField");

        verticalLayout_3->addWidget(descriptionField);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        picDisplay = new QLabel(AddSkillWindow);
        picDisplay->setObjectName("picDisplay");
        picDisplay->setMinimumSize(QSize(128, 128));
        picDisplay->setMaximumSize(QSize(128, 128));

        verticalLayout->addWidget(picDisplay);

        picButton = new QPushButton(AddSkillWindow);
        picButton->setObjectName("picButton");

        verticalLayout->addWidget(picButton);


        verticalLayout_10->addLayout(verticalLayout);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_3 = new QLabel(AddSkillWindow);
        label_3->setObjectName("label_3");

        verticalLayout_5->addWidget(label_3);

        statNameComboBox = new QComboBox(AddSkillWindow);
        statNameComboBox->setObjectName("statNameComboBox");

        verticalLayout_5->addWidget(statNameComboBox);


        verticalLayout_9->addLayout(verticalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_4 = new QLabel(AddSkillWindow);
        label_4->setObjectName("label_4");

        verticalLayout_8->addWidget(label_4);

        minField = new QSpinBox(AddSkillWindow);
        minField->setObjectName("minField");

        verticalLayout_8->addWidget(minField);


        horizontalLayout->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_5 = new QLabel(AddSkillWindow);
        label_5->setObjectName("label_5");

        verticalLayout_7->addWidget(label_5);

        valueField = new QSpinBox(AddSkillWindow);
        valueField->setObjectName("valueField");

        verticalLayout_7->addWidget(valueField);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_6 = new QLabel(AddSkillWindow);
        label_6->setObjectName("label_6");

        verticalLayout_6->addWidget(label_6);

        maxField = new QSpinBox(AddSkillWindow);
        maxField->setObjectName("maxField");

        verticalLayout_6->addWidget(maxField);


        horizontalLayout->addLayout(verticalLayout_6);


        verticalLayout_9->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);


        verticalLayout_10->addLayout(verticalLayout_9);


        horizontalLayout_2->addLayout(verticalLayout_10);


        verticalLayout_11->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        addButton = new QPushButton(AddSkillWindow);
        addButton->setObjectName("addButton");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(addButton);

        buttonBox = new QDialogButtonBox(AddSkillWindow);
        buttonBox->setObjectName("buttonBox");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        horizontalLayout_3->addWidget(buttonBox);


        verticalLayout_11->addLayout(horizontalLayout_3);


        verticalLayout_12->addLayout(verticalLayout_11);


        retranslateUi(AddSkillWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddSkillWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddSkillWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddSkillWindow);
    } // setupUi

    void retranslateUi(QDialog *AddSkillWindow)
    {
        AddSkillWindow->setWindowTitle(QCoreApplication::translate("AddSkillWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddSkillWindow", "Nom", nullptr));
        label_2->setText(QCoreApplication::translate("AddSkillWindow", "Description", nullptr));
        picDisplay->setText(QString());
        picButton->setText(QCoreApplication::translate("AddSkillWindow", "Ajouter une image...", nullptr));
        label_3->setText(QCoreApplication::translate("AddSkillWindow", "Statistiques", nullptr));
        label_4->setText(QCoreApplication::translate("AddSkillWindow", "Min", nullptr));
        label_5->setText(QCoreApplication::translate("AddSkillWindow", "Value", nullptr));
        label_6->setText(QCoreApplication::translate("AddSkillWindow", "Max", nullptr));
        addButton->setText(QCoreApplication::translate("AddSkillWindow", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddSkillWindow: public Ui_AddSkillWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSKILLWINDOW_H
