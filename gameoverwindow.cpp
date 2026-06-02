#include "gameoverwindow.h"
#include "ui_gameoverwindow.h"

GameOverWindow::GameOverWindow(int score, int best, QWidget *parent)
    : QWidget(parent), ui(new Ui::GameOverWindow) {
    ui->setupUi(this);
    setFixedSize(600, 600);
    // Підставляємо значення
    ui->scoreLabel->setText(QString::number(score));
    ui->bestLabel->setText(QString("Рекорд: %1").arg(best));
}

GameOverWindow::~GameOverWindow() { delete ui; }

void GameOverWindow::on_playAgainButton_clicked() {
    emit playAgain();
}

void GameOverWindow::on_menuButton_clicked() {
    emit goToMenu();
}
