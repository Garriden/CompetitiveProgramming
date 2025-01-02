#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;


bool arePermutation(const string &str1, const string &str2) {
    if(str1.size() != str2.size()) {
        return false;
    }
    
    unordered_map<char,int> map;
    
    for(int ii = 0; ii < str1.size(); ++ii) {
        map[str1[ii]]++;
    }
  
    for(int ii = 0; ii < str2.size(); ++ii) {
        if(map[str2[ii]] > 0) {
            map[str2[ii]]--;
        }
    }
    
    for(int ii = 0; ii < str1.size(); ++ii) {
        if(map[str1[ii]] != 0) {
            return false;
        }
    }

    return true;
}
int main() {
    string str1 = "testest";
    string str2 = "estxest";
    if(arePermutation(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are NOOOT permutation of each other" << endl;
    str1 = "hello";
    str2 = "oellh";
     if(arePermutation(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are NOOOT permutation of each other" << endl;
      
    str1 = "holas";
    str2 = "pepsi";
     if(arePermutation(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are NOOOT permutation of each other" << endl;
      
    return 0;
}
