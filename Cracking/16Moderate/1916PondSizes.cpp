#include <iostream>
#include <cmath>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <limits.h>
#include <queue>

// g++ 1916PondSizes.cpp -o hola

// BFS

int main()
{
    std::vector<int> res;
    std::vector<std::vector<int> > M = { {0,2,1,0}, {0,1,0,1}, {1,1,0,1}, {0,1,0,1} };
    std::vector<std::vector<bool> > checked(4, std::vector<bool>(4, false));
    std::queue<std::pair<int, int> > Q;

    int rowSize = M.size();
    int columnSize = M[0].size();
    int poundSize = 0;

    for(int row = 0; row < rowSize; ++row) {
        for(int col = 0; col < columnSize; ++col) {
            
            if(!checked[row][col]) {
                checked[row][col] = true;

                if(M[row][col] == 0) { // Look for all boundaries.
                    
                    Q.push({row, col});

                    while(!Q.empty()) {
                        
                        std::pair<int, int> p = Q.front();
                        int localRow = p.first;
                        int localCol = p.second;
                        Q.pop();

                        // all left and top boundaries already checked.
                        // just check bot, right, and bot-right diagonal.
                        if(localCol < columnSize - 1) { // right
                            if(M[localRow][localCol+1] == 0) {
                                if(!checked[localRow][localCol+1]) {
                                    Q.emplace(localRow, localCol+1); // Add to the queue of water.
                                }
                            }
                        }

                        if(localRow < rowSize - 1) { // bot
                            if(M[localRow+1][localCol] == 0) {
                                if(!checked[localRow+1][localCol]) {
                                    Q.emplace(localRow+1, localCol); // Add to the queue of water.
                                }
                            }
                        }

                        if(localRow < rowSize - 1 && localCol < columnSize - 1) { // bot-right diagonal.
                            if(M[localRow+1][localCol+1] == 0) {
                                if(!checked[localRow+1][localCol+1]) {
                                    Q.emplace(localRow+1, localCol+1); // Add to the queue of water.
                                }
                            }
                        }

                        if(localRow < rowSize - 1) { // bot-left diagonal.
                            if(M[localRow+1][localCol-1] == 0) {
                                if(!checked[localRow+1][localCol-1]) {
                                    Q.emplace(localRow+1, localCol-1); // Add to the queue of water.
                                }
                            }
                        }

                        checked[localRow][localCol] = true;
                        ++poundSize;
                    }
                    res.push_back(poundSize);
                    poundSize = 0;
                }
            }
        }
    }

    for(int ii = 0; ii < res.size(); ++ii) {
        std::cout << res[ii] << " ";
    } std::cout << std::endl;

    return 0;
}