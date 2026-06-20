#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QWidget>
#include <QTimer>
#include <QPainter>

static const int GRID_SIZE = 8;
static const int CELL_SIZE = 45;
QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE
class GameWindow : public QWidget {
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    void startNewGame();
signals:
    void backToMenu();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private slots:
    void on_settingsButton_clicked();
private:
    Ui::GameWindow *ui;
    int grid[GRID_SIZE][GRID_SIZE];
    QColor gridColors[GRID_SIZE][GRID_SIZE];
    int currentScore;
    int bestScore;
    struct Block {
        QVector<QPoint> cells;
        QColor color;
        QPoint drawPos;
        bool used;
    };
    Block pieces[3];
    int dragPieceIndex;
    QPoint dragPos;
    bool isDragging;
    QTimer *clearAnimTimer;
    QVector<int> animRows;
    QVector<int> animCols;
    int animAlpha;
    bool isAnimating;
    void generatePieces();
    void drawBlock(QPainter &p, int x, int y, QColor col, int size);
    void drawGrid(QPainter &p);
    void drawPieces(QPainter &p);
    bool canPlace(int pieceIdx, int row, int col);
    void placePiece(int pieceIdx, int row, int col);
    void checkAndClearLines();
    void checkGameOver();
    void saveScore();
    void loadScore();
    void updateScoreLabels();
    QPoint gridOrigin();

};
#endif
