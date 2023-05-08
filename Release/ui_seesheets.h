/********************************************************************************
** Form generated from reading UI file 'seesheets.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEESHEETS_H
#define UI_SEESHEETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_seeSheets
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout;
    QListWidget *listPlayer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;

    void setupUi(QDialog *seeSheets)
    {
        if (seeSheets->objectName().isEmpty())
            seeSheets->setObjectName("seeSheets");
        seeSheets->resize(700, 500);
        label = new QLabel(seeSheets);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 20, 701, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Black")});
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(seeSheets);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(150, 80, 416, 321));
        verticalLayout_10 = new QVBoxLayout(layoutWidget);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_5);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        listPlayer = new QListWidget(layoutWidget);
        listPlayer->setObjectName("listPlayer");

        verticalLayout->addWidget(listPlayer);


        verticalLayout_8->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout->addWidget(pushButton_4);


        verticalLayout_8->addLayout(horizontalLayout);


        verticalLayout_9->addLayout(verticalLayout_8);


        verticalLayout_10->addLayout(verticalLayout_9);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout_10->addWidget(pushButton_3);


        retranslateUi(seeSheets);

        QMetaObject::connectSlotsByName(seeSheets);
    } // setupUi

    void retranslateUi(QDialog *seeSheets)
    {
        seeSheets->setWindowTitle(QCoreApplication::translate("seeSheets", "Fiche de Joueur", nullptr));
        label->setText(QCoreApplication::translate("seeSheets", "Saisissez le nom du joueur pour y voir sa fiche", nullptr));
        label_5->setText(QCoreApplication::translate("seeSheets", "Liste des Entit\303\251s", nullptr));
        pushButton->setText(QCoreApplication::translate("seeSheets", "Voir la fiche", nullptr));
        pushButton_2->setText(QCoreApplication::translate("seeSheets", "Ajouter une Statistique", nullptr));
        pushButton_4->setText(QCoreApplication::translate("seeSheets", "Ajouter les valeurs des Statistiques", nullptr));
        pushButton_3->setText(QCoreApplication::translate("seeSheets", "Modifier la Liste", nullptr));
    } // retranslateUi

};

namespace Ui {
    class seeSheets: public Ui_seeSheets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEESHEETS_H
