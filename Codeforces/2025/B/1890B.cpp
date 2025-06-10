//https://codeforces.com/contest/1890/problem/B
// Div. 2
// 750  *800

// Qingshan Loves Strings

// g++ -o b b.cpp

// constructive algorithms
// implementation

// Just make NO as default and in which cases YES.
// It failed the corner case when the second string were not ok.
//  was wrong because if the first string it's OK, doesn't need to look at the second string.
//  "do the following operation any number of times (possibly, zero)."

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, m, x, k;
    ll a, b, p;
    std::string s, t;
    std::cin >> n;
    std::cin >> m;
    std::cin >> s;
    std::cin >> t;

    int sZeros = 0;
    int sOnes = 0;
    int tZeros = 0;
    int tOnes = 0;

    bool sConsecutiveOnes = false;
    bool sConsecutiveZeros = false;
    bool tConsecutiveOnes = false;
    bool tConsecutiveZeros = false;
    bool sHasDifferences = false;


    if(n <= 1) { // 0)
        std::cout << "Yes" << std::endl;
        return;
    }


    char before = t[0];
    if(t[0] == '0') { // important to check the first.
        ++tZeros;
    } else {
        ++tOnes;
    }
    bool bad = false;
    // count t.
    for(int ii = 1; ii < m; ++ii) {

        if(t[ii] == '0') {
            ++tZeros;
        } else {
            ++tOnes;
        }


        if(t[ii] == '0' && before == '0') {
            tConsecutiveZeros = true;
        }
        if(t[ii] == '1' && before == '1') {
            tConsecutiveOnes = true;
        }

        // 1) t cannot have adjacent chars.
        if(!bad && t[ii] == before) {
            bad = true;
        }

        before = t[ii];
    }

    // BAD! It is possible to NOT use t!
    //if(bad) { // 1) t cannot have adjacent chars.
    //    std::cout << "No" << std::endl;
    //    return;
    //}

    before = s[0]; // again watchout this and make sure that the next ii starts at 1.
    if(s[0] == '0') {
        ++sZeros;
    } else {
        ++sOnes;
    }
    // count s.
    for(int ii = 1; ii < n; ++ii) { // watchout n or m, copy paste !
        if(s[ii] == '0') {
            ++sZeros;
        } else {
            ++sOnes;
        }


        if(s[ii] == '0' && before == '0') {
            sConsecutiveZeros = true;
        } else {
            sHasDifferences = true;
        }

        if(s[ii] == '1' && before == '1') {
            sConsecutiveOnes = true;
        } else {
            sHasDifferences = true;
        }

        before = s[ii];
    }

    if((!sConsecutiveOnes && !sConsecutiveZeros)) {
        std::cout << "yES" << std::endl;
        return;
    }

    //std::cout << "sZeros: " << sZeros << std::endl;
    //std::cout << "sOnes: " << sOnes << std::endl;

    // 2)
    //if(t[0] == '0' && t[t.size() - 1] == '0' && sZeros == 0) {
    //    std::cout << "yEs" << std::endl;
    //    return;
    //}
    //if(t[0] == '1' && t[t.size() - 1] == '1' && sOnes == 0) {
    //    std::cout << "yEs" << std::endl;
    //    return;
    //}



    // 3)
    if(t[0] == '0' && t[t.size() - 1] == '0' && !bad && !sConsecutiveZeros) {
        std::cout << "yeS" << std::endl;
        return;
    } 
    if(t[0] == '1' && t[t.size() - 1] == '1' && !bad && !sConsecutiveOnes) {
        std::cout << "yeS" << std::endl;
        return;
    }


    //// 2a)
    //if(t[0] == '0' && t[t.size() - 1] == '0' && sZeros > 0) {
    //    std::cout << "no" << std::endl;
    //    return;
    //}
    //if(t[0] == '1' && t[t.size() - 1] == '1' && sOnes > 0) {
    //    std::cout << "no" << std::endl;
    //    return;
    //}

    // 4)
    //if(t[0] !=  t[t.size() - 1] && (sConsecutiveOnes || sConsecutiveZeros)) {
    //    std::cout << "NO" << std::endl;
    //    return;
    //} else {
    //    //std::cout << "YES" << std::endl;
    //}

    std::cout << "NO" << std::endl;

    //std::cout << "contPartitions: " << contPartitions << std::endl;
    //std::cout << contPartitions << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        // Watch test failing trick.
        /*
        if(t == (2000 - 137)) {  // but N: found [137th token]
            int n,m;
            std::string s, t;
            std::cin >> n;
            std::cin >> m;
            std::cin >> s;
            std::cin >> t;
            //std::string out = "s: " + s + " / t: " + t;
            std::string out = t;
            std::cout << out << std::endl;
        }
        */
        solve();
    }

}
