#include "game.h"

Game::Game() {
    resetBoard();
    currentPlayer = HUMAN;
}

bool Game::makeMove(int row, int col, Player player) {
    if (!isMoveValid(row, col)) {
        return false;
    }
    board[row][col] = player;
    return true;
}

Player Game::checkWinner() const {
    // Winning conditions
    for (int i = 0; i < 3; ++i) {
        // Check rows and columns
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // Check diagonals
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return EMPTY;
}

bool Game::isBoardFull() const {
    for (const auto& row : board) {
        for (Player cell : row) {
            if (cell == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

void Game::resetBoard() {
    board = std::vector<std::vector<Player>>(3, std::vector<Player>(3, EMPTY));
    currentPlayer = HUMAN;
}

std::pair<int, int> Game::getBestMove() {
    int bestVal = -1000;
    std::pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == EMPTY) {
                board[i][j] = COMPUTER;
                int moveVal = minimax(0, false);
                board[i][j] = EMPTY;
                if (moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

const std::vector<std::vector<Player>>& Game::getBoard() const {
    return board;
}

bool Game::isMoveValid(int row, int col) const {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY;
}

int Game::minimax(int depth, bool isMaximizing) {
    Player winner = checkWinner();
    if (winner == COMPUTER) return 10 - depth;
    if (winner == HUMAN) return depth - 10;
    if (isBoardFull()) return 0;

    if (isMaximizing) {
        int best = -1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = COMPUTER;
                    best = std::max(best, minimax(depth + 1, !isMaximizing));
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = HUMAN;
                    best = std::min(best, minimax(depth + 1, !isMaximizing));
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    }
}
