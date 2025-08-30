#include <iostream>
#include <cmath>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <limits.h>
#include <numeric> // Required for std::accumulate

// g++ -std=c++17 2216LangtonAnt.cpp -o hola

// How to predict how much data structure do I need ?
//  1- Large fixed vectors Matrix.
//  2- Test how many iterations costs size of Matrix.
//  3- Resizable array.
//  4- Keep four variables, mins and maxs ? How do I know if square is white or black ?
//  5- Map where key is coordenate pair. Build map from minimum coordenate pair somehow. (Tricky)
//      The map just stores black squares. Keep consistent dependent top-left cordenates.

#define RIGHT 0
#define BOT   1
#define LEFT  2
#define TOP   3

void PrintKMoves5(int K) // TODO.
{

}

void PrintKMoves1(int K)
{
    std::vector<std::vector<bool> > M(10, std::vector<bool>(10, false)); // false = white. true = black.
    int facing = RIGHT;
    int col = 5;
    int row = 5;

    for(int ii = 0; ii < K; ++ii) {
        if(M[row][col] == false) { // White.
            ++facing;
        } else { // Black.
            --facing;
        }

        M[row][col] = !M[row][col];

        if(facing % 4 == RIGHT) {
            ++col;
        } else if(facing % 4 == BOT) {
            ++row;
        } else if(facing % 4 == LEFT) {
            --col;
        } else if(facing % 4 == TOP) {
            --row;
        }
    }

    for(int ii = 0; ii < M.size(); ++ii) {
        for(int jj = 0; jj < M[0].size(); ++jj) {
            std::cout << M[ii][jj] << " ";
        }
        std::cout << std::endl;
    }

}

int main()
{
    PrintKMoves1(200);

    return 0;
}