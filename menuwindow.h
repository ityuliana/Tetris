#include <QMainWindow>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui { class MenuWindow; }
QT_END_NAMESPACE

class MenuWindow : public QWidget {
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

private slots:
    void on_playButton_clicked();
    void on_exitButton_clicked();

private:
    Ui::MenuWindow *ui;
    QPropertyAnimation *logoAnimation;
};

//#endif
