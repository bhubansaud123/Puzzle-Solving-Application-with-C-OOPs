
#include <iostream>
#include <vector>
using namespace std;

/*
  PuzzleBoard Class
  Represents a 3x3 sliding puzzle
*/
class PuzzleBoard {
private:
    vector<vector<int>> board;
    int emptyRow, emptyCol;

public:
    PuzzleBoard() {
        board = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 0, 8}
        };

        emptyRow = 2;
        emptyCol = 1;
    }

    void displayBoard() const {
        cout << "\nCurrent Puzzle State:\n";
        for (auto row : board) {
            for (int val : row) {
                if (val == 0)
                    cout << "  ";
                else
                    cout << val << " ";
            }
            cout << endl;
        }
    }

    bool moveTile(char direction) {
        int newRow = emptyRow;
        int newCol = emptyCol;

        if (direction == 'w') newRow--;
        else if (direction == 's') newRow++;
        else if (direction == 'a') newCol--;
        else if (direction == 'd') newCol++;
        else return false;

        if (newRow < 0 || newRow >= 3 || newCol < 0 || newCol >= 3)
            return false;

        swap(board[emptyRow][emptyCol], board[newRow][newCol]);
        emptyRow = newRow;
        emptyCol = newCol;
        return true;
    }

    bool isSolved() const {
        vector<vector<int>> solved = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
        };
        return board == solved;
    }
};

/*
  Game Class
  Controls the puzzle gameplay
*/
class PuzzleGame {
private:
    PuzzleBoard board;

public:
    void startGame() {
        char move;
        cout << "===== Advanced Puzzle Solver =====\n";
        cout << "Controls:\n";
        cout << "w = up | s = down | a = left | d = right\n";

        while (true) {
            board.displayBoard();

            if (board.isSolved()) {
                cout << "\n🎉 Puzzle Solved Successfully!\n";
                break;
            }

            cout << "Enter move: ";
            cin >> move;

            if (!board.moveTile(move)) {
                cout << "Invalid move! Try again.\n";
            }
        }
    }
};

int main() {
    PuzzleGame game;
    game.startGame();
    return 0;
}




// # 🧩 Advanced Puzzle Solver Application (OOP-Based)

// An **Object-Oriented Puzzle Solver** written in **C++**, implementing the classic **8-Puzzle (Sliding Puzzle)** problem.  
// This project is ideal for **students, beginners, and interview preparation**.

// ---

// ## 🚀 Features
// - OOP-based design
// - Puzzle board abstraction
// - Valid move checking
// - Win condition detection
// - STL usage (`vector`)
// - Clean and extendable code

// ---

// ## 🧠 OOP Concepts Used
// - Classes & Objects
// - Encapsulation
// - Abstraction
// - Composition
// - Constructors
// - Member functions

// ---

// ## 🎮 Controls
// | Key | Action |
// |----|-------|
// | w | Move Up |
// | s | Move Down |
// | a | Move Left |
// | d | Move Right |

// ---

// ## 📂 Project Structure
