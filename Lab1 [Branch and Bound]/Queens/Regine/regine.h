#include <iostream>
#include <fstream>

namespace rgn {

    int sizeOfSides();

    const int n = sizeOfSides();

    int board[20][20];

    int sizeOfSides() {

        std::ifstream file("in.txt");
        char data;
        int number = 0;

        if (file.is_open()) {
            data = file.get();
            number = data - '0';
        }
        file.close();

        return number;
    }

    void setBoardToZero() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = 0;
    }

    void printBoard()
    {

        std::ofstream file("out.txt");

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {
                std::cout << board[i][j] << " ";

                file << board[i][j] << " ";
            }
                
            std::cout << "\n";
            file << "\n";
        }

    }

    bool isSafe(int row, int col)
    {
        int i, j;

        for (i = 0; i < col; i++)
            if (board[row][i])
                return false;

        return true;
    }

    bool solveNQUtil(int col)
    {
        
        if (col >= n)
            return true;

        for (int i = 0; i < n; i++) {
            
            if (isSafe(i, col)) {
                board[i][col] = 1;

             if (solveNQUtil(col + 1))
                    return true;

             board[i][col] = 0;
            }
        }

        return false;
    }

    bool solveNQ()
    {
        setBoardToZero();
        
        if (solveNQUtil(0) == false) {
            std::cout << "Nu există o soluție validă.";
            return false;
        }

        printBoard();

        return true;
    }

}