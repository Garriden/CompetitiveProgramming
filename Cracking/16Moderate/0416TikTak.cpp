#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

// g++ 0416TikTak.cpp -o hola

bool HasWon(const std::vector<std::vector<char> > &M, char c)
{
    if(M[0][0] == c && M[0][1] == c && M[0][2] == c) return true;
    if(M[1][0] == c && M[1][1] == c && M[1][2] == c) return true;
    if(M[2][0] == c && M[2][1] == c && M[2][2] == c) return true;

    if(M[0][0] == c && M[1][0] == c && M[2][0] == c) return true;
    if(M[0][1] == c && M[1][1] == c && M[2][1] == c) return true;
    if(M[0][2] == c && M[1][2] == c && M[2][2] == c) return true;

    if(M[0][0] == c && M[1][1] == c && M[2][2] == c) return true;
    if(M[2][0] == c && M[1][1] == c && M[0][2] == c) return true;

    return false;
}

int main()
{
    int n = 24;
    std::vector<std::vector<char> > M = { {'X', 'O', 'X'},
                                          {'O', 'O', '.'},
                                          {'X', 'O', 'X'}};
    bool Owin = HasWon(M, 'O');
    bool Xwin = HasWon(M, 'X');

    if(!Owin && !Xwin) std::cout << "No winner." << std::endl;
    if(Owin && Xwin) std::cout << "Impossible game." << std::endl;
    if(Owin && !Xwin) std::cout << "O player wins!" << std::endl;
    if(!Owin && Xwin) std::cout << "X player wins!" << std::endl;

    return 0;
}