#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), playWithComputer(false), currentPlayer(HUMAN) {
    ui->setupUi(this);

    QGridLayout *layout = new QGridLayout;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            buttons[i][j] = new QPushButton("");
            buttons[i][j]->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
            buttons[i][j]->setMinimumSize(100, 100); // Set a minimum size for visibility
            buttons[i][j]->setFont(QFont("Arial", 24));
            layout->addWidget(buttons[i][j], i, j);
            connect(buttons[i][j], &QPushButton::clicked, [=]() { handleButtonClick(i, j); });
        }
    }

    ui->centralwidget->setLayout(layout);
    startNewGame();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::handleButtonClick(int row, int col) {
    if (game.makeMove(row, col, currentPlayer)) {
        updateBoard();
        checkGameOver();
        if (!playWithComputer) {
            // Toggle between HUMAN and COMPUTER
            currentPlayer = (currentPlayer == HUMAN) ? COMPUTER : HUMAN;
        } else {
            if (!game.isBoardFull() && game.checkWinner() == EMPTY) {
                auto [compRow, compCol] = game.getBestMove();
                game.makeMove(compRow, compCol, COMPUTER);
                updateBoard();
                checkGameOver();
            }
        }
    }
}

void MainWindow::startNewGame() {
    GameModeDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        playWithComputer = dialog.isPlayWithComputer();
        game.resetBoard();
        updateBoard();
        currentPlayer = HUMAN; // Reset to HUMAN at the start of a new game
    }
}

void MainWindow::updateBoard() {
    const auto& board = game.getBoard();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == HUMAN) {
                buttons[i][j]->setText("X");
            } else if (board[i][j] == COMPUTER) {
                buttons[i][j]->setText("O");
            } else {
                buttons[i][j]->setText("");
            }
        }
    }
}

void MainWindow::checkGameOver() {
    Player winner = game.checkWinner();
    if (winner != EMPTY || game.isBoardFull()) {
        QString message;
        if (winner == HUMAN) {
            message = "You win!";
        } else if (winner == COMPUTER) {
            message = "Computer wins!";
        } else {
            message = "It's a draw!";
        }
        QMessageBox::information(this, "Game Over", message);
        startNewGame();
    }
}
