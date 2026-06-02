/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QPushButton *exitButton;
    QPushButton *playButton;
    QLabel *logoLabel;

    void setupUi(QWidget *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName("MenuWindow");
        MenuWindow->resize(400, 600);
        MenuWindow->setStyleSheet(QString::fromUtf8("background-color: #003087;"));
        exitButton = new QPushButton(MenuWindow);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(240, 530, 151, 51));
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #003087;\n"
"    color: #FFD600;\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    border-radius: 25px;\n"
"    border: 2px solid #FFD600;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #004DB3;\n"
"}"));
        playButton = new QPushButton(MenuWindow);
        playButton->setObjectName("playButton");
        playButton->setGeometry(QRect(110, 300, 181, 61));
        playButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #FFD600;\n"
"    color: #003087;\n"
"    font-size: 22px;\n"
"    font-weight: bold;\n"
"    border-radius: 27px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #FFE033;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFC000;\n"
"}"));
        logoLabel = new QLabel(MenuWindow);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setGeometry(QRect(110, 50, 181, 131));
        logoLabel->setStyleSheet(QString::fromUtf8("color: #FFD600;\n"
"font-size: 52px;\n"
"font-weight: bold;\n"
"letter-spacing: 4px;"));

        retranslateUi(MenuWindow);

        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QWidget *MenuWindow)
    {
        MenuWindow->setWindowTitle(QCoreApplication::translate("MenuWindow", "Form", nullptr));
        exitButton->setText(QCoreApplication::translate("MenuWindow", "\320\222\320\230\320\245\320\206\320\224", nullptr));
        playButton->setText(QCoreApplication::translate("MenuWindow", "\342\226\266  \320\223\320\240\320\220\320\242\320\230", nullptr));
        logoLabel->setText(QCoreApplication::translate("MenuWindow", "BLOCK\n"
"BLAST", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
