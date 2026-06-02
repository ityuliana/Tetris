/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QPushButton *replayButton;
    QPushButton *exitButton;

    void setupUi(QWidget *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName("SettingsWindow");
        SettingsWindow->resize(250, 300);
        SettingsWindow->setStyleSheet(QString::fromUtf8("background-color: #4A148C;\n"
"border-radius: 15px;"));
        replayButton = new QPushButton(SettingsWindow);
        replayButton->setObjectName("replayButton");
        replayButton->setGeometry(QRect(50, 90, 141, 51));
        replayButton->setStyleSheet(QString::fromUtf8("QPushButton { background-color: #FFD600; color: #1A237E; font-size: 18px; font-weight: bold; border-radius: 22px; }\n"
"QPushButton:hover { background-color: #FFE033; }"));
        exitButton = new QPushButton(SettingsWindow);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(50, 160, 141, 51));
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton { background-color: transparent; color: white; font-size: 18px; font-weight: bold; border-radius: 22px; border: 2px solid white; }\n"
"QPushButton:hover { background-color: rgba(255,255,255,20); }"));

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QWidget *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QCoreApplication::translate("SettingsWindow", "Form", nullptr));
        replayButton->setText(QCoreApplication::translate("SettingsWindow", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\270", nullptr));
        exitButton->setText(QCoreApplication::translate("SettingsWindow", "\320\222\320\270\321\205\321\226\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
