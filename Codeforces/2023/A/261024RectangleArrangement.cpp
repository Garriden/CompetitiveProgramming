#include <bits/stdc++.h>
#include <iostream>
#include <bitset>
#define ll long long
using namespace std;
 
//g++ -o hola hola.cpp
 
int main() {
    int t, n, CA, w, h;
    ll a;
    std::cin >> t;
    while(t--) {
        ll oddNums = 0;
        ll sum = 0;
        ll minim = INT_MAX;
        ll maxim = 0;
        ll maximC = 0;
        ll minimC = 0;

        std::cin >> n;
        int N = n;

        bitset<32> mybits = bitset<32>(a);

        int top=0;
        int bot=0;
        int right=0;
        int left=0;
        int maxH = 0;
        int maxW = 0;
        int ii = 0;
        while(ii < N) {
            cin >> w >> h;

            if(w>maxW) {
                top += (w-maxW);
                bot += (w-maxW);

                maxW = w;
            } 
            
            if(h>maxH) {
                right += (h-maxH);
                left += (h-maxH);

                maxH = h;
            }

            ii++;
        }

        //std::cout << "sum: " << sum << std::endl;
        std::cout << left+right+top+bot << std::endl;
    }
 
}