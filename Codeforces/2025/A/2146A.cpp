// https://codef
// Div. 2
// 500
// 
//1140

// N

// g++ -o a a.cpp

// co

// C

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, x, y, k, l, r;
    ll a, b, p;
    std::string s;
    ll modulo = 998244353;
    ll max = 0;

    std::cin >> n;
    ll N = n;

    std::vector<ll> v(n);
    std::map<ll, ll> freq;

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> v[ii];
        freq[v[ii]]++;
    }

    std::vector<std::pair<ll, ll> > sortedFreq;
    for(auto pair : freq) {
        sortedFreq.push_back({pair.second, pair.first});
    }

    std::sort(sortedFreq.rbegin(), sortedFreq.rend());

    //for(int ii = 0; ii < sortedFreq.size(); ++ii) {
    //    std::cout << "Number: " << sortedFreq[ii].second << ", Freq: " << sortedFreq[ii].first << std::endl;
    //} std::cout << std::endl;

    ll index = 2;
    for(int ii = 0; ii < sortedFreq.size(); ++ii) {
        ll frequency = sortedFreq[ii].first;
        max = std::max(max, frequency);
        //std::cout << "max: " << max << ", frequency: " << frequency << std::endl;

        if(ii < sortedFreq.size() - 1) {
            sortedFreq[ii+1].first = sortedFreq[ii+1].first * index;
        }
        ++index;
        //std::cout << "Number: " << pair.second << ", Freq: " << pair.first << std::endl;


    }
    
    //std::cout << "max: " << max << std::endl;
    std::cout << max << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
