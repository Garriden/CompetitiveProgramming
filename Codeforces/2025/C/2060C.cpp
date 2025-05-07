// Game of Mathletes
//https://codeforces.com/contest/2060/problem/C
// Div. 3
// 900

//g++ -o a a.cpp

// Games
// Greedy
// Sortings ?
// Two Pointers ?
// Complement
// Map frequency

// Playing Optimally, Bob will counter Alice with a number that will sum k.
//  So numbers could be separated into paired and non paired numbers.
//  I need to create a map of frequencies and see if the other number exists (hasn't been removed).
//BUG: the double if check: if the two numbers are the same number, on the second check must be already decremented.
// O(n)

#include <bits/stdc++.h>
#define ll unsigned long long

// O(n).        input + map freq.
// O(n*log*n).  Sort. NO NEEDED
// O(n).        Iterate and find paired numbers. n/2 ?

int main() {
    ll t, n, CA;
    ll a, b, k;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        int ret = 0;
        std::cin >> n;
        std::cin >> k;
        std::map<int,int> freq;
        std::vector<int> v(n);

        // O(n).        input + map freq.
        for(int ii = 0; ii < n; ++ii) {
            std::cin >> a;
            v[ii] = a;
            freq[a]++;
        }

        // O(n*log*n).  Sort.
        //std::sort(v.begin(), v.end());

        // O(n).      Iterate and find paired numbers.
        for(int ii = 0; ii < n; ++ii) {
            int value = v[ii];
            //std::cout << "value: " << v[ii] << " freq: " << freq[value]  << " freq Oposite: "  << freq[k-value] << std::endl;
            if(freq[value]-- > 0 && freq[k-value]-- > 0) { // Brutal!
                //--freq[k-value];
                //--freq[value];
                ++ret;
            }
        }

        std::cout << ret << std::endl;
    }
    return 0;
}