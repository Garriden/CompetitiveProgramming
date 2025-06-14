//https://codeforces.com/contest/1895/problem/C
// Educational Div.2
// 1400

// Torn Lucky Ticket

// g++ -o a a.cpp

// TE
// O(n^2)

// brute force
// dp
// hashing
// implementation
// math

// Be aware of:
// Revise conditions statement again.

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
        //std::vector<std::vector<std::string> > EvenSumDigits(45, std::vector<std::string>(0, ""));
        //std::vector<std::vector<std::string> > OddSumDigits(45, std::vector<std::string>(0, ""));
        std::map<std::string, int> stringFreqEven;
        std::map<std::string, int> stringFreqOdd;

        std::map<std::string, int> sumDigits;

        //std::vector<std::strings> vs(n, 0);
        for(int ii = 0; ii < n; ++ii) {
            std::cin >> s1;
            //std::cout << s1 << std::endl;
            int sum = SumDigitsString(s1);
            sumDigits[s1] = sum;
            //std::cout << " sum: " << sum << std::endl;

            if(s1.size() % 2 == 0) {
                stringFreqEven[s1]++;
                
                //std::vector<std::string> aux = EvenSumDigits[sum];
                //aux.push_back(s1);
                //for(int kk = 0; kk < aux.size(); ++kk) {
                //    std::cout << aux[kk] << std::endl;
                //}
                //EvenSumDigits[sum] = aux;

            } else {
                stringFreqOdd[s1]++;

                //std::vector<std::string> aux = OddSumDigits[sum];
                //aux.push_back(s1);
                //for(int kk = 0; kk < aux.size(); ++kk) {
                //    std::cout << aux[kk] << std::endl;
                //}
                //OddSumDigits[sum] = aux;
            }
        }

        //for(auto pair : stringFreqOdd) {
        //    std::cout << "key: " << pair.first << "   value: " << pair.second<< std::endl;
        //}

        int cont = 0;

        int reps = 0;
        std::string s2 = "";
        std::string sFirstHalf;
        std::string sSecondHalf;
        int sum1 = 0;
        int sum2 = 0;
        for(auto pair : stringFreqEven) {
            for(auto pairTwo : stringFreqEven) {
                reps = pair.second * pairTwo.second;
                
                        s2 = pair.first + pairTwo.first;
                        sFirstHalf = s2.substr(0, s2.size()/2);
                        sSecondHalf = s2.substr(s2.size()/2);

                        //if(sumDigits[sFirstHalf]) {
                        if(sumDigits.count(sFirstHalf)) {
                            sum1 = sumDigits[sFirstHalf];
                        } else {
                            sum1 = SumDigitsString(sFirstHalf);
                            sumDigits[sFirstHalf] = sum1;
                        }

                        if(sumDigits.count(sSecondHalf)) {
                            sum2 = sumDigits[sSecondHalf];
                        } else {
                            sum2 = SumDigitsString(sSecondHalf);
                            sumDigits[sSecondHalf] = sum2;
                        }
                        
                        //std::cout << " s2 even: " << s2 << std::endl;
                        if(sum1 == sum2) {
                            while(reps --> 0) {
                                ++cont;
                            }
                        }
            }
        }
        for(auto pair : stringFreqOdd) {
            for(auto pairTwo : stringFreqOdd) {
                reps = pair.second * pairTwo.second;
                        s2 = pair.first + pairTwo.first;
                        sFirstHalf = s2.substr(0, s2.size()/2);
                        sSecondHalf = s2.substr(s2.size()/2);

                        if(sumDigits.count(sFirstHalf)) {
                            sum1 = sumDigits[sFirstHalf];
                        } else {
                            sum1 = SumDigitsString(sFirstHalf);
                            sumDigits[sFirstHalf] = sum1;
                        }

                        if(sumDigits.count(sSecondHalf)) {
                            sum2 = sumDigits[sSecondHalf];
                        } else {
                            sum2 = SumDigitsString(sSecondHalf);
                            sumDigits[sSecondHalf] = sum2;
                        }
                        
                        //std::cout << " s2 even: " << s2 << std::endl;
                        if(sum1 == sum2) {
                            while(reps --> 0) {
                                ++cont;
                            }
                        }
                    
                
            }
        }

        //std::cout << "cont: " << cont << std::endl;
        std::cout << cont << std::endl;

        //for(int ii = 0; ii < 45; ++ii) {
        //    if(EvenSumDigits[ii].size() > 0) {
        //        for(int jj = 0; jj < EvenSumDigits[ii].size(); ++jj) {
        //            std::cout << "EvenSumDigits: " << EvenSumDigits[ii][jj] << std::endl;
        //        }
        //    }
        //}
        //for(int ii = 0; ii < 45; ++ii) {
        //    if(OddSumDigits[ii].size() > 0) {
        //        for(int jj = 0; jj < OddSumDigits[ii].size(); ++jj) {
        //            std::cout << "OddSumDigits: " << OddSumDigits[ii][jj] << std::endl;
        //        }
        //    }
        //}


        //for(int ii = 0; ii < n; ++ii) {
        //    //std::cin >> va[ii];
        //    std::cout << va[ii] << " " << va[n*2 - 1 - ii] << std::endl;
        //}

        //std::cout << "contPartitions: " << contPartitions << std::endl;
        //std::cout << contPartitions << std::endl;

    //}

}
