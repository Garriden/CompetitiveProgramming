//https://codeforces.com/contest/2110/problem/A
// Div. 2
// 500

// Fashionable Array

// g++ -o a a.cpp

// Implementation
// Sortings

// Lol, messy code (programming from mobilephone).
// Cerca (break).

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

int main() {
    ll t, n, m, x;
    ll a, b, p;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> n;
        ll sum = 0;
        ll firstPointer = 0;
        ll lastPointer = n - 1;

        std::vector<ll> va(n);
        
        
        for(int ii = 0; ii < n; ++ii) {
            std::cin >> a;
            va[ii] = a;
        }

        std::sort(va.begin(), va.end());


ll firstDistance = 0;
ll lastDistance = 0;
bool firsteven = true;
if(va[0] % 2 == 1){ //0dd
  firsteven=false;
}

for(int ii = 1; ii < n; ++ii) {
  if(firsteven) {
    if(va[ii]% 2 == 0) { //nothi
    
    } else { // ojo
firstDistance = ii;
break;
}
} else { //odd
if(va[ii]% 2 == 0) {
     firstDistance = ii;
     break;
    }else {
  
}

}
}


bool lasteven = true;
if(va[lastPointer] % 2 == 1){ //0dd
  lasteven=false;
}

for(int ii = n-2; ii >=0; --ii) {
  if(lasteven) {
    if(va[ii]% 2 == 0) { //nothi
     
    } else { // ojo
lastDistance = n-ii-1;
break;

}
} else { //odd
if(va[ii]% 2 == 0) {
     lastDistance = n-ii-1;
     break;
    } else {
      
    }
    }
}


if(firsteven == lasteven){
std::cout <<0 << std::endl;

} else {
        std::cout << std::min(firstDistance, lastDistance) << std::endl;
}
        

    }

}