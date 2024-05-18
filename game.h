#ifndef GAME_H
#define GAME_H

#include <vector>
#include <utility>

enum Player { EMPTY, HUMAN, COMPUTER };

class Game {
public:
    Game();

    bool makeMove(int row, int col, Player player);
    Player checkWinner() const;
    bool isBoardFull() const;
    void resetBoard();
    std::pair<int, int> getBestMove();

    const std::vector<std::vector<Player>>& getBoard() const;

private:
    std::vector<std::vector<Player>> board;
    Player currentPlayer;
    bool isMoveValid(int row, int col) const;
    int minimax(int depth, bool isMaximizing);
    int evaluateBoard() const;
};

#endif // GAME_H
