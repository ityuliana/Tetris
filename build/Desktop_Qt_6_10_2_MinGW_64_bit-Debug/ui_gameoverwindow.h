/********************************************************************************
** Form generated from reading UI file 'gameoverwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVERWINDOW_H
#define UI_GAMEOVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameOverWindow
{
public:
    QWidget *widget;
    QLabel *titleLabel;
    QPushButton *playAgainButton;
    QLabel *scoreTitleLabel;
    QLabel *bestLabel;
    QLabel *scoreLabel;
    QLabel *crownLabel;
    QPushButton *menuButton;

    void setupUi(QWidget *GameOverWindow)
    {
        if (GameOverWindow->objectName().isEmpty())
            GameOverWindow->setObjectName("GameOverWindow");
        GameOverWindow->resize(600, 600);
        GameOverWindow->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        widget = new QWidget(GameOverWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(70, 50, 360, 460));
        widget->setStyleSheet(QString::fromUtf8("background-color: #4A148C;\n"
"border-radius: 20px;"));
        titleLabel = new QLabel(widget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(50, 70, 250, 48));
        titleLabel->setStyleSheet(QString::fromUtf8("color: #FFD600;\n"
"font-size: 36px;\n"
"font-weight: bold;"));
        playAgainButton = new QPushButton(widget);
        playAgainButton->setObjectName("playAgainButton");
        playAgainButton->setGeometry(QRect(40, 300, 281, 61));
        playAgainButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #FFD600;\n"
"    color: #4A148C;\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    border-radius: 27px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #FFE033;\n"
"}"));
        scoreTitleLabel = new QLabel(widget);
        scoreTitleLabel->setObjectName("scoreTitleLabel");
        scoreTitleLabel->setGeometry(QRect(130, 130, 81, 24));
        scoreTitleLabel->setStyleSheet(QString::fromUtf8("color: #CE93D8;\n"
"font-size: 18px;\n"
"qproperty-alignment: 'AlignCenter';\n"
""));
        bestLabel = new QLabel(widget);
        bestLabel->setObjectName("bestLabel");
        bestLabel->setGeometry(QRect(100, 250, 161, 27));
        bestLabel->setStyleSheet(QString::fromUtf8("color: #FFD600;\n"
"font-size: 20px;\n"
"qproperty-alignment: 'AlignCenter';"));
        scoreLabel = new QLabel(widget);
        scoreLabel->setObjectName("scoreLabel");
        scoreLabel->setGeometry(QRect(105, 160, 131, 61));
        scoreLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 64px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';"));
        crownLabel = new QLabel(widget);
        crownLabel->setObjectName("crownLabel");
        crownLabel->setGeometry(QRect(130, -10, 101, 71));
        crownLabel->setStyleSheet(QString::fromUtf8("font-size: 64px;"));
        menuButton = new QPushButton(widget);
        menuButton->setObjectName("menuButton");
        menuButton->setGeometry(QRect(40, 370, 281, 61));
        menuButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: white;\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    border-radius: 27px;\n"
"    border: 2px solid white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(255,255,255,20);\n"
"}"));

        retranslateUi(GameOverWindow);

        QMetaObject::connectSlotsByName(GameOverWindow);
    } // setupUi

    void retranslateUi(QWidget *GameOverWindow)
    {
        GameOverWindow->setWindowTitle(QCoreApplication::translate("GameOverWindow", "Form", nullptr));
        titleLabel->setText(QCoreApplication::translate("GameOverWindow", "\320\223\321\200\320\260 \320\267\320\260\320\272\321\226\320\275\321\207\320\265\320\275\320\260!", nullptr));
        playAgainButton->setText(QCoreApplication::translate("GameOverWindow", "\342\226\266  \320\223\321\200\320\260\321\202\320\270 \320\267\320\275\320\276\320\262\321\203", nullptr));
        scoreTitleLabel->setText(QCoreApplication::translate("GameOverWindow", "\320\240\320\260\321\205\321\203\320\275\320\276\320\272", nullptr));
        bestLabel->setText(QCoreApplication::translate("GameOverWindow", "\320\240\320\265\320\272\320\276\321\200\320\264: 0", nullptr));
        scoreLabel->setText(QCoreApplication::translate("GameOverWindow", "0", nullptr));
        crownLabel->setText(QCoreApplication::translate("GameOverWindow", "\360\237\221\221", nullptr));
        menuButton->setText(QCoreApplication::translate("GameOverWindow", "\360\237\217\240  \320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameOverWindow: public Ui_GameOverWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVERWINDOW_H
