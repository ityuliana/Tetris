#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class GameOverWindow; }
QT_END_NAMESPACE

class GameOverWindow : public QWidget {
    Q_OBJECT

public:
    explicit GameOverWindow(int score, int best, QWidget *parent = nullptr);
    ~GameOverWindow();

signals:
    void playAgain();
    void goToMenu();

private slots:
    void on_playAgainButton_clicked();
    void on_menuButton_clicked();

private:
    Ui::GameOverWindow *ui;
};

#endif
