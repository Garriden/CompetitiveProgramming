 #include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

// g++ -std=c++20 1208EightQueens.cpp -o hola

// Backtracking

void Occupy(bool addQueen, int row, int col, std::vector<std::vector<int> > &occupied)
{
    for(int ii = 0; ii < 8; ++ii) {
        for(int jj = 0; jj < 8; ++jj) {
            if(ii == row || jj == col || (ii - jj == row - col) || (ii + jj == row + col) ) {
                if(addQueen) {
                    occupied[ii][jj]++;
                } else {
                    occupied[ii][jj]--;
                }
            }
        }
    }

}

void PrintQueens(std::vector<std::vector<bool> > v)
{
    std::cout << "Final Queens: " << std::endl;
    for(int ii = 0; ii < 8; ++ii) {
        for(int jj = 0; jj < 8; ++jj) {
            std::cout << v[ii][jj] << " ";
        }
        std::cout << std::endl;
    }
}

bool AllEightQueens(int row, int col, std::vector<std::vector<bool> > table, std::vector<std::vector<int> > occupied, int queensPositioned)
{
    if(queensPositioned == 8) {
        PrintQueens(table);
        return true;
    }

    while(row < 8) {
        while(col < 8) {
            if(!occupied[row][col]) {

                ++queensPositioned;
                table[row][col] = true;
                Occupy(true, row, col, occupied);

                if(AllEightQueens(row, col, table, occupied, queensPositioned) == 8) {
                    return true;
                }

                // Backtracking.
                --queensPositioned;
                table[row][col] = false;
                Occupy(false, row, col, occupied);

            }

            ++col;
        }

        ++row;
        col = 0;
    }

    return false;
}

bool EightQueens(int row, std::vector<std::vector<bool> > table, std::vector<std::vector<int> > occupied)
{
    if(row == 8) { // Base Case.
        PrintQueens(table);
        return true;
    }

    for(int ii = 0; ii < 8; ++ii) {
        if(!occupied[row][ii]) {
            table[row][ii] = true;
            Occupy(true, row, ii, occupied);

            if(EightQueens(row + 1, table, occupied)) {
                return true;
            }

            table[row][ii] = false;
            Occupy(false, row, ii, occupied);
        }
    }

    return false;
}

int main()
{
    std::vector<std::vector<bool> >     table(8, (std::vector<bool>(8, false)) );
    std::vector<std::vector<int> >   occupied(8, (std::vector<int>(8, 0)) );
    //AllEightQueens(0, 0, table, occupied, 0);
    EightQueens(0, table, occupied);
    return 0;
}