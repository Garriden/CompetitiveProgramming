////https://codeforces.com/contest/2109/problem/B
// Div. 2
// 1000

// Slice to survive

//g++ -o b b.cpp

// Bit masks ?
// Greedy
// Matrix ?
// Log2
// Games

#include <iostream>
#include <bits/stdc++.h>
#define ll unsigned long long

// Greedy. I didn't get to work
/*
int main() {
    ll t, n, m, CA;
    ll a, b;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> n >> m >> a >> b;

        int turn = 0;
        std::cout << "n: " << n << "   m: " << m << std::endl;
        
        while(n > 2 || m > 2) {

            if(n-a > m-b) {
                if(a <= 2) { 
                    n = 2;
                }
                n = (n+1)/2;

            } else {
                if(b <= 2) {
                    m = 2;
                }
                m = (m+1)/2;
            }
            a = (n + 1) / 2;
            b = (m + 1) / 2;

            ++turn;
            std::cout << "turn-" << turn << "  n: " << n << "   m: " << m << "  /  a: " << a << "   b: " << b << std::endl;
        }



        std::cout << "turn: " << turn + 2 << std::endl;

    }

}
*/

int log2(int &x)
{
    int cont = 0;
    while(x > 1) {
        x = (x + 1) / 2;
        ++cont;
    }

    return cont;
}

int main() {
    int t, n, m, CA;
    int a, b;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> n >> m >> a >> b;

        int c = std::min(a, n-a+1);
        int d = std::min(b, m-b+1);

        std::cout << 1 + std::min(log2(c) + log2(m), log2(d) + log2(n)) << std::endl;
    }
}