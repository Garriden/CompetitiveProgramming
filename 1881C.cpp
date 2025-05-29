//https://codeforces.com/contest/1881/problem/C
// Div. 3
// 3

// Perfect Square

// DOESN'T WORK.

// g++ -o c c.cpp

// sortings
// greedy

/*
When rotating a matrix of size n by 90 degrees:

element a[i][j] takes the position of element a[j][n−1−i]
element a[n−1−j][i] takes the position of element a[i][j]
element a[n−1−i][n−1−j] takes the position of element a[n−1−j][i]
In order for the matrix to be a perfect square, the symbols at all of these positions must be equal.
Since we can only maximize a symbol, we do the following:

- Among these 4 symbols, let's find the lexicographically maximal one, that is, 
   the one that is in the alphabet not before all the others;
- For all characters that are not equal to the maximum, 
   calculate the number of operations that must be applied to them to make them equal to the maximum character.
   This number of operations is equal to the difference of positions of symbols in the alphabet.
*/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

int main() {
    ll t, n, m, x;
    ll a, b, c, p;
    std::string s1, s2;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> n;
        std::vector<std::string> M(n);
        int cont = 0;
        for(int ii = 0; ii < n; ++ii) {
            std::cin >> M[ii];
        }

        for(int ii = 0; ii < n; ++ii) {
            for(int jj = 0; jj < n; ++jj) {
                if(M[ii][jj] != M[jj][ii]) {
                    std::cout << "M[ii][jj]: " << M[ii][jj] << "  / M[jj][ii]" << M[jj][ii] << std::endl;
                    ++cont;
                }
            }
        }

        std::cout << "cont: " << cont << std::endl;
    }

}
