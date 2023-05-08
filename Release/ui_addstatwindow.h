/********************************************************************************
** Form generated from reading UI file 'addstatwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTATWINDOW_H
#define UI_ADDSTATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addstatwindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLineEdit *name;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QPushButton *addStat;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QListWidget *listWidget;
    QPushButton *delStat;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *addstatwindow)
    {
        if (addstatwindow->objectName().isEmpty())
            addstatwindow->setObjectName("addstatwindow");
        addstatwindow->resize(611, 433);
        verticalLayout_3 = new QVBoxLayout(addstatwindow);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(addstatwindow);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Black")});
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        name = new QLineEdit(addstatwindow);
        name->setObjectName("name");

        gridLayout->addWidget(name, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        label_2 = new QLabel(addstatwindow);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        addStat = new QPushButton(addstatwindow);
        addStat->setObjectName("addStat");

        gridLayout->addWidget(addStat, 2, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_6 = new QLabel(addstatwindow);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);

        listWidget = new QListWidget(addstatwindow);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        delStat = new QPushButton(addstatwindow);
        delStat->setObjectName("delStat");

        verticalLayout->addWidget(delStat);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(addstatwindow);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        verticalLayout_2->addWidget(buttonBox);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(addstatwindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, addstatwindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, addstatwindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(addstatwindow);
    } // setupUi

    void retranslateUi(QDialog *addstatwindow)
    {
        addstatwindow->setWindowTitle(QCoreApplication::translate("addstatwindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addstatwindow", "Ajouter des Nouvelles Statistique \303\240 la partie", nullptr));
        label_2->setText(QCoreApplication::translate("addstatwindow", "Nom ", nullptr));
        addStat->setText(QCoreApplication::translate("addstatwindow", "Ajouter la Stat", nullptr));
        label_6->setText(QCoreApplication::translate("addstatwindow", "Statistique d\303\251j\303\240 existantes", nullptr));
        delStat->setText(QCoreApplication::translate("addstatwindow", "Supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addstatwindow: public Ui_addstatwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTATWINDOW_H
