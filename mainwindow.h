#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "game.h"
#include "gamemodedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButtonClick(int row, int col);
    void startNewGame();

private:
    Ui::MainWindow *ui;
    Game game;
    QPushButton *buttons[3][3];
    bool playWithComputer;
    Player currentPlayer;
    void updateBoard();
    void checkGameOver();
};

#endif // MAINWINDOW_H
