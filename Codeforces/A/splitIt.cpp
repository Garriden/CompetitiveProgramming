/*********************
https://codeforces.com/problemset/problem/1496/A

A 900
brute force      
constructive algorithms      
greedy
strings

7
5 1
qwqwq
2 1
ab
3 1
ioi
4 2
icpc
22 0
dokidokiliteratureclub
19 8
imteamshanghaialice
6 3
aaaaaa

*************************/

#include <bits/stdc++.h>
#include <stdio.h>
#include <time.h>

int main() {
    int t;
    std::cin >> t;
    while(t-- > 0) {
        int n, m;
        std::cin >> n >> m;
        std::string s;
        std::cin >> s;
        
        if(2*m >= n){ 
            std::cout << "NO" << "\n";
        } else {

            for(int ii = 0; ii < m; ++ii) {
    			if(s[ii] != s[s.size() - 1 - ii]) {
    				std::cout << "NO" << std::endl;
    				break;
    			}
    		}
    		
    		std::cout << "YES" << std::endl;
        }
		
        //std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    }

    return 0;
}
