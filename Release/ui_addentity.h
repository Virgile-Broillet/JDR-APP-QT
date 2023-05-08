/********************************************************************************
** Form generated from reading UI file 'addentity.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDENTITY_H
#define UI_ADDENTITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addEntity
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *Name;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *Type;
    QLabel *label_11;
    QSpinBox *InventorySlotNB;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QPlainTextEdit *Desc;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *addSkills;
    QPushButton *ImageBrowser;
    QPushButton *addEntityButton;
    QGraphicsView *imagePicShow;
    QLabel *Imagelabel;

    void setupUi(QDialog *addEntity)
    {
        if (addEntity->objectName().isEmpty())
            addEntity->setObjectName("addEntity");
        addEntity->resize(700, 500);
        label = new QLabel(addEntity);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 10, 701, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Black")});
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(addEntity);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(148, 120, 353, 274));
        verticalLayout_7 = new QVBoxLayout(layoutWidget);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        Name = new QLineEdit(layoutWidget);
        Name->setObjectName("Name");

        verticalLayout_2->addWidget(Name);


        verticalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout_4->addWidget(label_4);

        Type = new QLineEdit(layoutWidget);
        Type->setObjectName("Type");

        verticalLayout_4->addWidget(Type);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName("label_11");

        verticalLayout_4->addWidget(label_11);

        InventorySlotNB = new QSpinBox(layoutWidget);
        InventorySlotNB->setObjectName("InventorySlotNB");
        InventorySlotNB->setMaximum(255);

        verticalLayout_4->addWidget(InventorySlotNB);


        verticalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        Desc = new QPlainTextEdit(layoutWidget);
        Desc->setObjectName("Desc");
        Desc->setEnabled(true);

        verticalLayout_3->addWidget(Desc);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        addSkills = new QPushButton(layoutWidget);
        addSkills->setObjectName("addSkills");

        horizontalLayout_5->addWidget(addSkills);

        ImageBrowser = new QPushButton(layoutWidget);
        ImageBrowser->setObjectName("ImageBrowser");

        horizontalLayout_5->addWidget(ImageBrowser);


        verticalLayout_6->addLayout(horizontalLayout_5);

        addEntityButton = new QPushButton(layoutWidget);
        addEntityButton->setObjectName("addEntityButton");

        verticalLayout_6->addWidget(addEntityButton);


        verticalLayout_7->addLayout(verticalLayout_6);

        imagePicShow = new QGraphicsView(addEntity);
        imagePicShow->setObjectName("imagePicShow");
        imagePicShow->setGeometry(QRect(150, 90, 50, 50));
        Imagelabel = new QLabel(addEntity);
        Imagelabel->setObjectName("Imagelabel");
        Imagelabel->setGeometry(QRect(150, 90, 50, 50));

        retranslateUi(addEntity);

        QMetaObject::connectSlotsByName(addEntity);
    } // setupUi

    void retranslateUi(QDialog *addEntity)
    {
        addEntity->setWindowTitle(QCoreApplication::translate("addEntity", "Ajouter une Entit\303\251", nullptr));
        label->setText(QCoreApplication::translate("addEntity", "Ajouter de Nouvelles entit\303\251s", nullptr));
        label_7->setText(QCoreApplication::translate("addEntity", "Ajout d'une Entit\303\251", nullptr));
        label_2->setText(QCoreApplication::translate("addEntity", "Nom", nullptr));
        label_4->setText(QCoreApplication::translate("addEntity", "Type", nullptr));
        label_11->setText(QCoreApplication::translate("addEntity", "Place d'inventaire", nullptr));
        label_3->setText(QCoreApplication::translate("addEntity", "Description", nullptr));
        addSkills->setText(QCoreApplication::translate("addEntity", "Ajouter des comp\303\251tences", nullptr));
        ImageBrowser->setText(QCoreApplication::translate("addEntity", "Ajouter une image...", nullptr));
        addEntityButton->setText(QCoreApplication::translate("addEntity", "Ajouter une Entit\303\251", nullptr));
        Imagelabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class addEntity: public Ui_addEntity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDENTITY_H
