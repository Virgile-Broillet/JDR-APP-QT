/********************************************************************************
** Form generated from reading UI file 'musicwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICWINDOW_H
#define UI_MUSICWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MusicWindow
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *MusicWindow)
    {
        if (MusicWindow->objectName().isEmpty())
            MusicWindow->setObjectName("MusicWindow");
        MusicWindow->resize(700, 500);
        pushButton = new QPushButton(MusicWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(310, 230, 80, 24));

        retranslateUi(MusicWindow);

        QMetaObject::connectSlotsByName(MusicWindow);
    } // setupUi

    void retranslateUi(QDialog *MusicWindow)
    {
        MusicWindow->setWindowTitle(QCoreApplication::translate("MusicWindow", "Musiques", nullptr));
        pushButton->setText(QCoreApplication::translate("MusicWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicWindow: public Ui_MusicWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICWINDOW_H
