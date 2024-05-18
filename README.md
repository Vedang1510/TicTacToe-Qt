# TicTacToe-Qt

A TicTacToe game built using Qt with options to play against a friend or the computer. The computer player uses the Minimax algorithm to make optimal moves.

## Features

- Play against a friend
- Play against the computer
- Intelligent AI using Minimax algorithm

## Getting Started

### Prerequisites

- Qt 5.12 or later
- C++11 or later

### Building the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/TicTacToe-Qt.git
   cd TicTacToe-Qt
2. Open the project in Qt Creator:
      Open Qt Creator.
      Go to File -> Open File or Project....
      Select TicTacToe-Qt.pro.

3. Build and run the project:
      Click on the Build button (hammer icon) or press Ctrl+B.
      Click the Run button (green play icon) or press Ctrl+R.

How to Play

    Choose whether to play against a friend or the computer.
    If playing with a friend, take turns clicking the buttons to place X's and O's.
    If playing against the computer, the computer will automatically make its move after you place your X.

Approaches Used
Minimax Algorithm

The Minimax algorithm is used to implement the AI for the computer player. It is a recursive algorithm used to choose an optimal move for the computer player assuming that the opponent is also playing optimally.
Steps of Minimax Algorithm:

    Generate the game tree: Generate the game tree for all possible moves up to a certain depth.
    Score the terminal nodes: Evaluate the board from the perspective of the maximizing player (computer) and assign scores.
    Backpropagate the scores: Use the minimax decision rule to propagate the scores back to the current game state.
    Choose the best move: The computer chooses the move with the maximum score.

File Structure

    mainwindow.ui: UI file for the main window.
    mainwindow.h, mainwindow.cpp: Main window implementation.
    game.h, game.cpp: Game logic and Minimax algorithm implementation.
    gamemodedialog.ui: UI file for the game mode selection dialog.
    gamemodedialog.h, gamemodedialog.cpp: Game mode dialog implementation.
