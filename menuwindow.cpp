#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "gamewindow.h"
#include <QApplication>

MenuWindow::MenuWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::MenuWindow) {
    ui->setupUi(this);
    setFixedSize(400, 600);

    QTimer::singleShot(0, this, [this]() {
        int w = ui->logoLabel->width();
        int h = ui->logoLabel->height();
        int x = ui->logoLabel->x();
        int endY = ui->logoLabel->y();

        logoAnimation = new QPropertyAnimation(ui->logoLabel, "geometry");
        logoAnimation->setDuration(800);
        logoAnimation->setStartValue(QRect(x, -h, w, h));
        logoAnimation->setEndValue(QRect(x, endY, w, h));
        logoAnimation->setEasingCurve(QEasingCurve::OutBounce);
        logoAnimation->start();
    });
}

MenuWindow::~MenuWindow() { delete ui; }

void MenuWindow::on_playButton_clicked() {
    GameWindow *game = new GameWindow();
    game->show();
    // Центруємо як меню
    game->move(this->geometry().center() - game->rect().center());
    this->hide();
    connect(game, &GameWindow::backToMenu, this, [this, game]() {
        game->close();
        this->show(); });
}
void MenuWindow::on_exitButton_clicked() { QApplication::quit(); }
