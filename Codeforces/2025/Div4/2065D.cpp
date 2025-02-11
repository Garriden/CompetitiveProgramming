//https://codeforces.com/contest/2065/problem/D

//g++ -o a 2065D.cpp

// Skibidus and Sigma
// I need a map because I want to order the sum of all the elements of the vectors.
// I need a multimap to repeat the Key, if one sum is repeated.
// to iterate a map backwards:  for(auto it = biggest.rbegin(); it != biggest.rend(); ++it)

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int t, n, m;
    int a, b;
    std::cin >> n >> m;

    int it = 0;
    std::vector<std::vector<int> > v(n, std::vector<int>(m));
    std::multimap<int,int> biggest; //Key = sum, Value = position.
    while(it < n) {
        int sumi = 0;
        for(int ii = 0; ii < m; ++ii) {
            cin >> a;
            v[it][ii] = a;
            sumi += a;
        }
        biggest.insert({sumi, it});
        ++it;
    }

    long long sumAux = 0;
    long long sum = 0;
    for(auto it = biggest.rbegin(); it != biggest.rend(); ++it) {
        for(int ii = 0; ii < m; ++ii) {
            sumAux += v[it->second][ii];
            sum += sumAux;
        }
    }
    std::cout << sum << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while(t--) solve();
}