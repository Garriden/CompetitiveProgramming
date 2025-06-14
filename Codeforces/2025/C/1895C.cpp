//https://codeforces.com/contest/1895/problem/C
// Educational Div.2
// 1400

// Torn Lucky Ticket

// g++ -o c c.cpp

// brute force
// dp
// hashing
// implementation
// math


/*
Be aware of:
  . 10^5 -> 99999 -> max sum digits = 45. 
  . Strings, each of length at most 5.
That means that a search for & for will TE Q(n^2).
Soand we will need a vetor (matrix) 6x46 to run it at Q(n).

When this happens, we can't to a second for, we need to have the "operation" already computed in a structure.

In the input: ++SizeSumFrequencyMatrix[vs[ii].size()][sum];

And then, in a for of every element, check in the "little" matrix instead of an another for.

For every element, "calculate" how many other element are complementaries.
(Search that complementary on the frequency matrix).
*/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

int SumDigitsString(std::string s) {
    int sum = 0;

    for(int ii = 0; ii < s.size(); ++ii) {
        sum += s[ii] - '0';
    }

    return sum;
}

void solve() {
    
}

int main() {
    int t;
    //std::cin >> t;

    //while(t --> 0) {
        //solve();
        ll n, x, y, k;
        ll a, b, p;
        std::string s1;
        std::cin >> n;

        // 10^5 -> 99999 -> max sum digits = 45
        std::vector<std::vector<ll> > SizeSumFrequencyMatrix(6, std::vector<ll>(45 + 1, 0));
        //std::map<std::string, int> stringFreqEven;
        //std::map<std::string, int> stringFreqOdd;
        //std::map<std::string, int> sumDigits;

        std::vector<std::string> vs(n);
        for(int ii = 0; ii < n; ++ii) {
            std::cin >> vs[ii];
            ll sum = SumDigitsString(vs[ii]);

            // increment the appearance of sum with these size
            ++SizeSumFrequencyMatrix[vs[ii].size()][sum];
        }

        //for(int ii = 0; ii < 6; ++ii) {
        //    for(int jj = 0; jj < 46; ++jj) {
        //        std::cout << SizeSumFrequencyMatrix[ii][jj] << " ";
        //    }
        //    std::cout << std::endl;
        //}


        ll cont = 0;

        for(int ii = 0; ii < n; ++ii) {
            //std::cout << "ii --- " << ii << std::endl;
            ll sum = SumDigitsString(vs[ii]);
            
            // equal length
            cont += SizeSumFrequencyMatrix[vs[ii].size()][sum];
            //std::cout << " mid cont: " << cont << std::endl;

            // left side
            ll left = 0;
            ll right = sum;
            ll len = vs[ii].size();
            for(int jj = 0; jj < (vs[ii].size() - 1) / 2; ++jj) {
                --len;
                char character = vs[ii][jj];
                left  += character - '0';
                right -= character - '0';

                //std::cout << "vs[ii] = " << vs[ii] << " / L-> left: " << left << "  / right: " << right << std::endl;

                ll diff = right - left; // left could be lower, see if it matches some right sum
                if(diff > 0) {
                    cont += SizeSumFrequencyMatrix[len - (jj + 1)][diff];
                    //std::cout << "+cont!" << std::endl;
                }

            }
            //std::cout << std::endl;

            // right side
            left = 0;
            right = sum;
            len = vs[ii].size();
            for(int jj = 0; jj < (vs[ii].size() - 1) / 2; ++jj) {
                --len;
                char character = vs[ii][vs[ii].size() - (jj + 1)];
                left  += character - '0';
                right -= character - '0';
                //std::cout << "vs[ii] = " << vs[ii] << " / R-> left: " << left << "  / right: " << right << std::endl;
                
                ll diff = right - left; // left could be lower, see if it matches some right sum
                if(diff > 0) {
                    cont += SizeSumFrequencyMatrix[len - (jj + 1)][diff];
                }
            }

        }

        //std::cout << "cont: " << cont << std::endl;
        std::cout << cont << std::endl;
}
