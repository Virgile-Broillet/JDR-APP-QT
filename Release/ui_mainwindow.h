/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNouvelle_partie;
    QAction *actionCharger_une_partie;
    QAction *actionEnregistrer_la_partie;
    QAction *actionQuitter;
    QAction *actionComment_utiliser_l_application;
    QAction *actionA_propos;
    QAction *actionContact;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *statButton;
    QPushButton *itemWindowButton;
    QPushButton *skillWindowButton;
    QPushButton *entityWindowButton;
    QPushButton *backgroundButton;
    QSpacerItem *verticalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *mapDisplay;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuAide;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionNouvelle_partie = new QAction(MainWindow);
        actionNouvelle_partie->setObjectName("actionNouvelle_partie");
        actionCharger_une_partie = new QAction(MainWindow);
        actionCharger_une_partie->setObjectName("actionCharger_une_partie");
        actionEnregistrer_la_partie = new QAction(MainWindow);
        actionEnregistrer_la_partie->setObjectName("actionEnregistrer_la_partie");
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName("actionQuitter");
        actionComment_utiliser_l_application = new QAction(MainWindow);
        actionComment_utiliser_l_application->setObjectName("actionComment_utiliser_l_application");
        actionA_propos = new QAction(MainWindow);
        actionA_propos->setObjectName("actionA_propos");
        actionContact = new QAction(MainWindow);
        actionContact->setObjectName("actionContact");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        statButton = new QPushButton(centralwidget);
        statButton->setObjectName("statButton");
        statButton->setStyleSheet(QString::fromUtf8("background-color: rgb(70, 70, 70);\n"
"color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(154, 154, 154);"));

        verticalLayout->addWidget(statButton);

        itemWindowButton = new QPushButton(centralwidget);
        itemWindowButton->setObjectName("itemWindowButton");
        itemWindowButton->setStyleSheet(QString::fromUtf8("background-color: rgb(70, 70, 70);\n"
"color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(154, 154, 154);"));

        verticalLayout->addWidget(itemWindowButton);

        skillWindowButton = new QPushButton(centralwidget);
        skillWindowButton->setObjectName("skillWindowButton");
        skillWindowButton->setStyleSheet(QString::fromUtf8("background-color: rgb(70, 70, 70);\n"
"color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(154, 154, 154);"));

        verticalLayout->addWidget(skillWindowButton);

        entityWindowButton = new QPushButton(centralwidget);
        entityWindowButton->setObjectName("entityWindowButton");
        entityWindowButton->setStyleSheet(QString::fromUtf8("background-color: rgb(70, 70, 70);\n"
"color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(154, 154, 154);"));

        verticalLayout->addWidget(entityWindowButton);

        backgroundButton = new QPushButton(centralwidget);
        backgroundButton->setObjectName("backgroundButton");
        backgroundButton->setStyleSheet(QString::fromUtf8("background-color: rgb(70, 70, 70);\n"
"color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(154, 154, 154);"));

        verticalLayout->addWidget(backgroundButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 657, 557));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName("verticalLayout_2");
        mapDisplay = new QLabel(scrollAreaWidgetContents);
        mapDisplay->setObjectName("mapDisplay");

        verticalLayout_2->addWidget(mapDisplay);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);


        verticalLayout_3->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName("menuFichier");
        menuAide = new QMenu(menubar);
        menuAide->setObjectName("menuAide");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionNouvelle_partie);
        menuFichier->addAction(actionCharger_une_partie);
        menuFichier->addAction(actionEnregistrer_la_partie);
        menuFichier->addAction(actionQuitter);
        menuAide->addAction(actionComment_utiliser_l_application);
        menuAide->addAction(actionA_propos);
        menuAide->addAction(actionContact);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestionnaire de Jeu de R\303\264le", nullptr));
        actionNouvelle_partie->setText(QCoreApplication::translate("MainWindow", "Nouvelle partie", nullptr));
        actionCharger_une_partie->setText(QCoreApplication::translate("MainWindow", "Charger une partie", nullptr));
        actionEnregistrer_la_partie->setText(QCoreApplication::translate("MainWindow", "Enregistrer la partie", nullptr));
        actionQuitter->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        actionComment_utiliser_l_application->setText(QCoreApplication::translate("MainWindow", "Comment utiliser l'application", nullptr));
        actionA_propos->setText(QCoreApplication::translate("MainWindow", "A propos", nullptr));
        actionContact->setText(QCoreApplication::translate("MainWindow", "Contact", nullptr));
        statButton->setText(QCoreApplication::translate("MainWindow", "Ajouter une stat", nullptr));
        itemWindowButton->setText(QCoreApplication::translate("MainWindow", "Gestion des items", nullptr));
        skillWindowButton->setText(QCoreApplication::translate("MainWindow", "Gestion des skills", nullptr));
        entityWindowButton->setText(QCoreApplication::translate("MainWindow", "Gestion des entit\303\251es", nullptr));
        backgroundButton->setText(QCoreApplication::translate("MainWindow", "Choisir un terrain", nullptr));
        mapDisplay->setText(QString());
        menuFichier->setTitle(QCoreApplication::translate("MainWindow", "Fichier", nullptr));
        menuAide->setTitle(QCoreApplication::translate("MainWindow", "Aide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
