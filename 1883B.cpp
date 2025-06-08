//https://codeforces.com/contest/1883/problem/B
// Div. 3
// 1000  *900

// Chemistry

// g++ -o b b.cpp

// strings
// palindrome
// map
// frequency
// parity

// map char Frequenci.
// Convert to vector of pairs sortedFrequencies.
//   std::sort(sortedFrequencies.begin(), sortedFrequencies.end(),
//   [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
//           return a.second < b.second;
//   });
// Palindrome: if n odd, one charFrequency should be one, the other ones even.
//             if n even, all charFrequency must be even.
// Keep decrementing k.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, m, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n >> k;
    std::cin >> s;

    std::map<char,int> charFrequency;

    // Map the frecuency.
    for(int ii = 0; ii < s.size(); ++ii) {
        charFrequency[s[ii]]++;
    }

    int parity = n - k;

    if(parity < 2) {
        std::cout << "YES" << std::endl;
        return;
    }

    // First, order by frequency.
    // Convert to vector pairs.
    std::vector<std::pair<char, int> > sortedFrequencies;
    for(const auto& pair : charFrequency) {
        sortedFrequencies.push_back(pair);
    }
    
    // Sort frequencies with a custom comparison lambda.
    std::sort(sortedFrequencies.begin(), sortedFrequencies.end(),
                [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
                        return a.second < b.second;
                });

    //for(const auto& pair : sortedFrequencies) {
    //    std::cout << "Character: '" << pair.first << "', Frequency: " << pair.second << std::endl;
    //}


    if(parity % 2 == 1) { // Odd.
        // then just one letter must be odd, the rest even.
        bool oddFound = false;

        for(int ii = 0; ii < sortedFrequencies.size() - 1; ++ii) {//for(const auto& pair : charFrequency) {
            if(sortedFrequencies[ii].second % 2 == 1) {
                --k;
                if(k < 0) {
                    if(oddFound) { // Just one odd value please.
                        std::cout << "no" << std::endl;
                        return;
                    }
                    oddFound = true;
                }

            }
            //std::cout << "Character: '" << pair.first << "', Frequency: " << pair.second << std::endl;
        }

    } else { // even.
        bool oddFound = false;

        for(int ii = 0; ii < sortedFrequencies.size() - 1; ++ii) {
            if(sortedFrequencies[ii].second % 2 == 1) {
                --k;
                if(k < 0) {
                    std::cout << "nO" << std::endl;
                    return;
                }


            }
            //std::cout << "Character: '" << pair.first << "', Frequency: " << pair.second << std::endl;
        }
    }


    std::cout << "YEs" << std::endl;
    //std::cout << "cont: " << cont << std::endl;
    //std::cout << cont << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
