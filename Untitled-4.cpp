#include <iostream>
#include <vector>

class NQueens {
public:
    NQueens(int n) : board_size(n), solutions(0) {
        queens.resize(n, -1);
    }

    void solve() {
        solveRecursive(0);
    }

    void printSolutions() {
        std::cout << "Number of solutions for " << board_size << "-queens problem: " << solutions << "\n";
    }

private:
    void solveRecursive(int row) {
        if (row == board_size) {
            solutions++;
            printSolution();
            return;
        }

        for (int col = 0; col < board_size; col++) {
            if (isSafe(row, col)) {
                queens[row] = col;
                solveRecursive(row + 1);
                queens[row] = -1;  // Backtrack
            }
        }
    }

    bool isSafe(int row, int col) const {
        // Проверка, что ферзь находится в безопасной позиции
        for (int prev_row = 0; prev_row < row; prev_row++) {
            int prev_col = queens[prev_row];
            if (prev_col == col ||            // Проверка вертикали
                prev_col - prev_row == col - row ||  // Проверка диагонали "/"
                prev_col + prev_row == col + row) {  // Проверка диагонали "\"
                return false;
            }
        }
        return true;
    }

    void printSolution() const {
        std::cout << "Solution " << solutions << ":\n";
        for (int row = 0; row < board_size; row++) {
            for (int col = 0; col < board_size; col++) {
                std::cout << (queens[row] == col ? 'Q' : '.');
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    int board_size;
    int solutions;
    std::vector<int> queens;
};

int main() {
    int n;
    std::cout << "Enter the size of the chessboard (n): ";
    std::cin >> n;

    NQueens nqueens(n);
    nqueens.solve();
    nqueens.printSolutions();

    return 0;
}