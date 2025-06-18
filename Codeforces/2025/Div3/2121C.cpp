// https://codeforces.com/contest/1898/problem/C
// Div. 3
//

// Those Who Are With Us

// g++ -o c c.cpp

// greedy
// implementation
// matrix

// Don't be afraid of iterating the matrix lots of times.
// Time complexity still O(n^2) and cannot be improved.

// Can invert a map of frequencies with:
//    std::multimap<ll, ll, std::greater<ll> > FreqCols;
//    FreqRows.insert({row.second, row.first});

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k, m;
    ll a, b, p;
    std::string s1;
    std::cin >> n >> m;

    ll acont = 0;
    ll bcont = 0;

    std::vector<std::vector<ll> > M(n, std::vector<ll>(m));

    ll max = 0;
    std::map<ll, ll> repeatedRowsFreq;
    std::map<ll, ll> repeatedColumnsFreq;

    // Iterate and build matrix -> build map of frequencies.
    for(int ii = 0; ii < n; ++ii) {
        for(int jj = 0; jj < m; ++jj) {
            std::cin >> M[ii][jj];

            if(M[ii][jj] > max) {
                //std::cout << "localMax: " << M[ii][jj] << std::endl;
                max = M[ii][jj];

                repeatedRowsFreq.clear();
                repeatedColumnsFreq.clear();

                repeatedRowsFreq.insert({ii,1});
                repeatedColumnsFreq.insert({jj,1});
            } else if(M[ii][jj] == max) {
                repeatedRowsFreq[ii]++;
                repeatedColumnsFreq[jj]++;
            }
        }
    }

    std::multimap<ll, ll, std::greater<ll> > FreqRows;
    std::multimap<ll, ll, std::greater<ll> > FreqCols;

    // build multimap frequencies inverted.
    for(auto row : repeatedRowsFreq) {
        FreqRows.insert({row.second, row.first});
    }
    for(auto col : repeatedColumnsFreq) {
        FreqCols.insert({col.second, col.first});
    }

    //for(auto pair : FreqRows) {
    //    std::cout << "freq: " << pair.first << "  / row: " << pair.second << std::endl;
    //}
    //for(auto pair : FreqCols) {
    //    std::cout << "freq: " << pair.first << "  / col: " << pair.second << std::endl;
    //}

    // Convert the column or the row into 0s, and then iterate the matrix again.
    auto it1 = FreqRows.begin();
    ll firstKeyRow = it1->first;
    ll firstValueRow = it1->second;
    auto it2 = FreqCols.begin();
    ll firstKeyCol = it2->first;
    ll firstValueCol = it2->second;
    //std::cout << "firstValueRow: " << firstValueRow << "  / firstValueCol: " << firstValueCol << std::endl;
    if(firstKeyRow > firstKeyCol) {
        // erase rows
        for(int ii = 0; ii < m; ++ii) {
            M[firstValueRow][ii] = 0;
        }


        // check again ?
        repeatedColumnsFreq.clear();
        for(int ii = 0; ii < n; ++ii) {
            for(int jj = 0; jj < m; ++jj) {
                if(M[ii][jj] == max) {
                    repeatedColumnsFreq[jj]++;
                }
            }
        }

        //std::cout << "repeatedColumnsFreq.size(): " << repeatedColumnsFreq.size() << std::endl;
        if(repeatedColumnsFreq.size() > 1) {
            std::cout << max << std::endl;
            return;
        } else {
            std::cout << max - 1 << std::endl;
            return;
        }

    } else {
        // erase cols
        for(int ii = 0; ii < n; ++ii) {
            M[ii][firstValueCol] = 0;
        }


        // check again ?
        repeatedRowsFreq.clear();
        for(int ii = 0; ii < n; ++ii) {
            for(int jj = 0; jj < m; ++jj) {
                if(M[ii][jj] == max) {
                    //std::cout << "ii: " << ii << "  / jj: " << jj << "  ->val: " << M[ii][jj]  << std::endl;
                    repeatedRowsFreq[ii]++;
                }
            }
        }


        //std::cout << "repeatedRowsFreq.size(): " << repeatedRowsFreq.size() << std::endl;
        if(repeatedRowsFreq.size() > 1) {
            std::cout << max << std::endl;
            return;
        } else {
            std::cout << max - 1 << std::endl;
            return;
        }

    }

    //std::cout << "max: " << max - 1 << std::endl;
    //std::cout << max << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
