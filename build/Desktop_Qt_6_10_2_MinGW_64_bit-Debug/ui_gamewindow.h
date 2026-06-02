/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QPushButton *settingsButton;
    QLabel *scoreLabel;
    QLabel *bestIconLabel;
    QLabel *bestScoreLabel;

    void setupUi(QWidget *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName("GameWindow");
        GameWindow->resize(500, 650);
        GameWindow->setStyleSheet(QString::fromUtf8("background-color: #1A237E;"));
        settingsButton = new QPushButton(GameWindow);
        settingsButton->setObjectName("settingsButton");
        settingsButton->setGeometry(QRect(440, 10, 41, 31));
        settingsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: transparent;\n"
"    color: white;\n"
"    font-size: 26px;\n"
"    border: none;\n"
"}\n"
"QPushButton:hover {\n"
"    color: #FFD600;\n"
"}"));
        scoreLabel = new QLabel(GameWindow);
        scoreLabel->setObjectName("scoreLabel");
        scoreLabel->setGeometry(QRect(210, 20, 91, 61));
        scoreLabel->setStyleSheet(QString::fromUtf8("font-size: 48px;\n"
"font-weight: bold;\n"
"color: white;"));
        bestIconLabel = new QLabel(GameWindow);
        bestIconLabel->setObjectName("bestIconLabel");
        bestIconLabel->setGeometry(QRect(12, 12, 33, 32));
        bestIconLabel->setStyleSheet(QString::fromUtf8("font-size: 24px;\n"
"color: #FFD600;"));
        bestScoreLabel = new QLabel(GameWindow);
        bestScoreLabel->setObjectName("bestScoreLabel");
        bestScoreLabel->setGeometry(QRect(50, 22, 51, 21));
        bestScoreLabel->setStyleSheet(QString::fromUtf8("font-size: 20px;\n"
"font-weight: bold;\n"
"color: #FFD600;"));

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QWidget *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "Form", nullptr));
        settingsButton->setText(QCoreApplication::translate("GameWindow", "\342\232\231", nullptr));
        scoreLabel->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        bestIconLabel->setText(QCoreApplication::translate("GameWindow", "\360\237\221\221", nullptr));
        bestScoreLabel->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
