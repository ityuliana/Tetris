#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "gameoverwindow.h"
#include "ui_settingswindow.h"
#include <QPainter> // налаштування графіки
#include <QMouseEvent> //події миші
#include <QSettings> //збереження рекорд на диску
#include <QRandomGenerator>
#include <QDialog>

// масив кольорів для фігур
static const QColor COLORS[] = {
    {"#F44336"}, {"#FFD600"}, {"#4CAF50"},
    {"#2196F3"}, {"#FF9800"}, {"#9C27B0"}
};

// масив фігур(x,y)
static const QVector<QVector<QPoint>> SHAPES = {
    {{0,0},{1,0},{2,0}}, {{0,0},{0,1},{0,2}},
    {{0,0},{1,0},{0,1},{1,1}}, {{0,0},{1,0},{2,0},{3,0}},
    {{0,0},{0,1},{0,2},{0,3}}, {{0,0},{1,0},{1,1},{2,1}},
    {{0,0},{0,1},{1,1},{1,2}}, {{0,0},{1,0},{2,0},{1,1}},
    {{0,0},{1,0},{0,1}}, {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{2,0},{2,1}}, {{0,0},{1,0}},
    {{0,0},{0,1}}, {{0,0}},
    };

GameWindow::GameWindow(QWidget *parent) : QWidget(parent), ui(new Ui::GameWindow) {
    ui->setupUi(this);
    setFixedSize(500, 650);
    isAnimating = false; isDragging = false; dragPieceIndex = -1;
    setupGridWidgets();

    QTimer::singleShot(0, this, [this]() {
        QPoint center = QGuiApplication::primaryScreen()->geometry().center() - rect().center();
        center.setY(center.y() - 40);
        move(center);
    });

    clearAnimTimer = new QTimer(this);//для зникнення рядків
    connect(clearAnimTimer, &QTimer::timeout, this, [this]() {
        animAlpha -= 30;//зменшуємо прозорість
        updateGridWidgets();
        if(animAlpha <= 0) {
            clearAnimTimer->stop();
            isAnimating = false;
            for(int r : animRows)//очищаємо заповнені рядки
                for(int c = 0; c < GRID_SIZE; c++)
                    grid[r][c] = 0, gridColors[r][c] = Qt::transparent;
            for(int c : animCols)//очищаємо заповнені стовпчики
                for(int r = 0; r < GRID_SIZE; r++)
                    grid[r][c] = 0, gridColors[r][c] = Qt::transparent;
            animRows.clear(); animCols.clear();
            updateGridWidgets();
            saveScore(); checkGameOver();
        }
        update();//премальовуємо вікно
    });

    isAnimating = false; isDragging = false; dragPieceIndex = -1;//жодна фігура не вибрана
    loadScore(); startNewGame();
}

GameWindow::~GameWindow() { delete ui; }

void GameWindow::startNewGame() {
    for(int r = 0; r < GRID_SIZE; r++)
        for(int c = 0; c < GRID_SIZE; c++)
            grid[r][c] = 0, gridColors[r][c] = Qt::transparent;
    currentScore = 0; isDragging = false; dragPieceIndex = -1;
    updateGridWidgets();
    generatePieces(); updateScoreLabels(); update();
}

void GameWindow::updateScoreLabels() {
    ui->scoreLabel->setText(QString::number(currentScore));
    ui->bestScoreLabel->setText(QString::number(bestScore));
}

QPoint GameWindow::gridOrigin() {
    return QPoint((width() - GRID_SIZE * CELL_SIZE) / 2, 90);
}

void GameWindow::generatePieces() {
    int startY = gridOrigin().y() + GRID_SIZE * CELL_SIZE + 20;
    int w = width();
   // int pos[] = { w/8, w/2 - 30, w*6/8 - 20 };
    int pos[] = { w/6, w/2 - 20, w*4/6 };
    for(int i = 0; i < 3; i++)
        pieces[i] = {
            SHAPES[QRandomGenerator::global()->bounded((int)SHAPES.size())],
            COLORS[QRandomGenerator::global()->bounded(6)],
            QPoint(pos[i], startY), false
        };
}

void GameWindow::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);//згладжування країв
    drawPieces(p);
}

QString GameWindow::cellStyle(const QColor &color, bool occupied, bool preview, bool animating) const {
    if(preview) {
        return "background-color: rgba(255,255,255,60);"
               "border: 1px solid rgba(255,255,255,90);"
               "border-radius: 6px;";
    }

    if(animating) {
        return QString("background-color: rgba(255,255,255,%1);"
                       "border: none;"
                       "border-radius: 6px;").arg(animAlpha);
    }

    if(occupied) {
        QColor border = color.darker(130);
        return QString("background-color: %1;"
                       "border: 1px solid %2;"
                       "border-radius: 6px;")
            .arg(color.name(), border.name());
    }

    return "background-color: #1A2980;"
           "border: 1px solid #2A3990;"
           "border-radius: 6px;";
}

void GameWindow::setupGridWidgets() {
    QPoint o = gridOrigin();

    for(int r = 0; r < GRID_SIZE; r++) {
        for(int c = 0; c < GRID_SIZE; c++) {
            QFrame *cell = new QFrame(this);
            cell->setGeometry(o.x() + c * CELL_SIZE + 2,
                              o.y() + r * CELL_SIZE + 2,
                              CELL_SIZE - 4,
                              CELL_SIZE - 4);
            cell->show();
            gridCells[r][c] = cell;
        }
    }

}

void GameWindow::updateGridWidgets() {
    bool preview[GRID_SIZE][GRID_SIZE] = {};

    if(isDragging && dragPieceIndex >= 0) {
        QPoint o = gridOrigin();
        int col = (dragPos.x() - o.x()) / CELL_SIZE;
        int row = (dragPos.y() - o.y()) / CELL_SIZE;

        if(canPlace(dragPieceIndex, row, col)) {
            for(auto &cell : pieces[dragPieceIndex].cells) {
                int r = row + cell.y();
                int c = col + cell.x();
                if(r >= 0 && r < GRID_SIZE && c >= 0 && c < GRID_SIZE)
                    preview[r][c] = true;
            }
        }
    }

    for(int r = 0; r < GRID_SIZE; r++) {
        for(int c = 0; c < GRID_SIZE; c++) {
            bool anim = false;
            if(isAnimating) {
                for(int ar : animRows) if(ar == r) { anim = true; break; }
                if(!anim) for(int ac : animCols) if(ac == c) { anim = true; break; }
            }

            gridCells[r][c]->setStyleSheet(cellStyle(gridColors[r][c], grid[r][c], preview[r][c], anim));
        }
    }
}

void GameWindow::drawBlock(QPainter &p, int x, int y, QColor c, int s) {
    p.setBrush(c); p.setPen(c.darker(130));
    p.drawRoundedRect(x, y, s, s, 6, 6);
    p.setBrush(QColor(255,255,255,60)); p.setPen(Qt::NoPen);
    p.drawRoundedRect(x+3, y+3, s/2, 7, 3, 3);
}

void GameWindow::drawGrid(QPainter &p) {
    QPoint o = gridOrigin();
    p.setBrush(QColor("#0D1B5E")); p.setPen(Qt::NoPen);
    p.drawRoundedRect(o.x()-5, o.y()-5, GRID_SIZE*CELL_SIZE+10, GRID_SIZE*CELL_SIZE+10, 10, 10);

    for(int r = 0; r < GRID_SIZE; r++) {
        for(int c = 0; c < GRID_SIZE; c++) {
            int x = o.x()+c*CELL_SIZE, y = o.y()+r*CELL_SIZE;
            if(grid[r][c]) {
                QColor col = gridColors[r][c];
                bool anim = false;
                if(isAnimating) {
                    for(int ar : animRows) if(ar==r) { anim=true; break; }
                    if(!anim) for(int ac : animCols) if(ac==c) { anim=true; break; }
                }
                if(anim) col = QColor(255,255,255,animAlpha);
                p.setBrush(col); p.setPen(anim ? Qt::NoPen : col.darker(130));
                p.drawRoundedRect(x+2,y+2,CELL_SIZE-4,CELL_SIZE-4,6,6);
                if(!anim) {
                    p.setBrush(QColor(255,255,255,60)); p.setPen(Qt::NoPen);
                    p.drawRoundedRect(x+4,y+4,CELL_SIZE-20,8,3,3);
                }
            } else {
                p.setBrush(QColor("#1A2980")); p.setPen(QColor("#2A3990"));
                p.drawRoundedRect(x+2,y+2,CELL_SIZE-4,CELL_SIZE-4,6,6);
            }
        }
    }

    if(isDragging && dragPieceIndex >= 0) {
        int c=(dragPos.x()-o.x())/CELL_SIZE, r=(dragPos.y()-o.y())/CELL_SIZE;
        if(canPlace(dragPieceIndex,r,c)) {
            p.setBrush(QColor(255,255,255,50)); p.setPen(Qt::NoPen);
            for(auto &cell : pieces[dragPieceIndex].cells)
                p.drawRoundedRect(o.x()+(c+cell.x())*CELL_SIZE+2,
                                  o.y()+(r+cell.y())*CELL_SIZE+2,
                                  CELL_SIZE-4, CELL_SIZE-4, 6, 6);
        }
    }
}

void GameWindow::drawPieces(QPainter &p) {
    for(int i = 0; i < 3; i++) {
        if(pieces[i].used || (isDragging && dragPieceIndex==i)) continue;
        for(auto &cell : pieces[i].cells)
            drawBlock(p, pieces[i].drawPos.x()+cell.x()*40,
                      pieces[i].drawPos.y()+cell.y()*40, pieces[i].color, 36);
    }
    if(isDragging && dragPieceIndex >= 0)
        for(auto &cell : pieces[dragPieceIndex].cells)
            drawBlock(p, dragPos.x()+cell.x()*CELL_SIZE,
                      dragPos.y()+cell.y()*CELL_SIZE, pieces[dragPieceIndex].color, CELL_SIZE-4);
}

void GameWindow::mousePressEvent(QMouseEvent *event) {
    for(int i = 0; i < 3; i++) {
        if(pieces[i].used) continue;
        for(auto &cell : pieces[i].cells) {
            int x=pieces[i].drawPos.x()+cell.x()*40, y=pieces[i].drawPos.y()+cell.y()*40;
            if(QRect(x,y,36,36).contains(event->pos())) {
                isDragging=true; dragPieceIndex=i;
                dragPos=event->pos()-QPoint(CELL_SIZE/2,CELL_SIZE/2);
                updateGridWidgets();
                return;
            }
        }
    }
}

void GameWindow::mouseMoveEvent(QMouseEvent *event) {
    if(!isDragging) return;
    dragPos = event->pos()-QPoint(CELL_SIZE/2,CELL_SIZE/2);
    updateGridWidgets();
    update();
}

void GameWindow::mouseReleaseEvent(QMouseEvent *event) {
    if(!isDragging) return;
    isDragging = false;
    QPoint o = gridOrigin();
    int col=(dragPos.x()-o.x())/CELL_SIZE, row=(dragPos.y()-o.y())/CELL_SIZE;
    if(canPlace(dragPieceIndex,row,col)) {
        placePiece(dragPieceIndex,row,col);
        bool allUsed = true;
        for(int i=0; i<3; i++) if(!pieces[i].used) { allUsed=false; break; }
        if(allUsed) generatePieces();
        checkAndClearLines();
        checkGameOver();
    }
    dragPieceIndex = -1; updateGridWidgets(); update();
}

bool GameWindow::canPlace(int idx, int row, int col) {
    for(auto &cell : pieces[idx].cells) {
        int r=row+cell.y(), c=col+cell.x();
        if(r<0||r>=GRID_SIZE||c<0||c>=GRID_SIZE||grid[r][c]) return false;
    }
    return true;
}

void GameWindow::placePiece(int idx, int row, int col) {
    for(auto &cell : pieces[idx].cells) {
        int r=row+cell.y(), c=col+cell.x();
        grid[r][c]=1; gridColors[r][c]=pieces[idx].color; currentScore++;
    }
    updateGridWidgets();
    pieces[idx].used=true; updateScoreLabels();
}

void GameWindow::checkAndClearLines() {
    QVector<int> rows, cols;
    for(int r=0; r<GRID_SIZE; r++) {
        bool full=true;
        for(int c=0; c<GRID_SIZE; c++) if(!grid[r][c]) { full=false; break; }
        if(full) rows.append(r);
    }
    for(int c=0; c<GRID_SIZE; c++) {
        bool full=true;
        for(int r=0; r<GRID_SIZE; r++) if(!grid[r][c]) { full=false; break; }
        if(full) cols.append(c);
    }
    if(rows.isEmpty() && cols.isEmpty()) { saveScore(); return; }
    currentScore += (rows.size()+cols.size())*10;//+10 очків за кожен рядків/стовпчиків
    updateScoreLabels();
    animRows=rows; animCols=cols;
    animAlpha=255; isAnimating=true;
    updateGridWidgets();
    clearAnimTimer->start(30);
}

void GameWindow::checkGameOver() {
    for(int i=0; i<3; i++) {
        if(pieces[i].used) continue;
        for(int r=0; r<GRID_SIZE; r++)
            for(int c=0; c<GRID_SIZE; c++)
                if(canPlace(i,r,c)) return;
    }
    saveScore();
    GameOverWindow *gow = new GameOverWindow(currentScore, bestScore, this);
    connect(gow, &GameOverWindow::playAgain, this, [this,gow](){ gow->close(); startNewGame(); });
    connect(gow, &GameOverWindow::goToMenu,  this, [this,gow](){ gow->close(); emit backToMenu(); });
    gow->show();
}

void GameWindow::saveScore() {
    if(currentScore > bestScore) {
        bestScore = currentScore;
        QSettings s("BlockBlast","Game");
        s.setValue("bestScore", bestScore);//зберігає на диску
        updateScoreLabels();
    }
}

void GameWindow::loadScore() {
    bestScore = QSettings("BlockBlast","Game").value("bestScore",0).toInt();//завантажуємо рекод з диску
}

void GameWindow::on_settingsButton_clicked() {
    QDialog *dlg = new QDialog(this);//діалог
    Ui::SettingsWindow ui_s;
    ui_s.setupUi(dlg);//підключення
    connect(ui_s.replayButton, &QPushButton::clicked, this, [this,dlg](){ dlg->close(); startNewGame(); });
    connect(ui_s.exitButton,   &QPushButton::clicked, this, [this,dlg](){ dlg->close(); emit backToMenu(); });
    dlg->exec();
}
