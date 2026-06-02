# Block Blast 🎮

A Block Blast style puzzle game developed in Qt Creator (C++).

## Description
Place pieces on an 8×8 grid. Fill a row or column and it will disappear with animation.
The game ends when none of the three pieces can be placed.

## Functionality
- Main menu with logo animation
- Drag & drop figures with the mouse
- Position highlighting while dragging
- Animation of the disappearance of filled rows/columns
- Saving the record between sessions (QSettings)
- Loss window with score and record
- Settings: repeat the game or exit

## Technologies
- Qt Creator 6+
- C++17
- QPainter, QTimer, QSettings, QDialog
- Qt Widgets (.ui files)

## Launch
1. Open TETRIS.pro in Qt Creator
2. Build → Run
