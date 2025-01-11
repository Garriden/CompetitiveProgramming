#include <iostream>
#include <string>
#include <algorithm>

/*
  Just iterate.
  Time complexity: O(n)
*/

std::string StringCompression(const std::string &s) 
{
    if(s.size() < 1) {
        return s;
    }

    std::string ret = "";
    char before = s[0];
    int count = 1;

    for(int ii = 1; ii < s.size(); ++ii) {
        if(s[ii] == before) {
            ++count;
        } else {
            ret += s[ii-1];

            std::string number = "";
            while(count > 9) {
                int aux = count%10;
                number += '0' + count%10;
                count /= 10;
            }
            number += '0' + count;

            std::reverse(number.begin(), number.end());
            ret += number;

            count = 1;
        }
        before = s[ii];
    }
    ret += s[s.size()-1];
    ret += '0' + count;

    if(ret.size() >= s.size()) {
        ret = s;
    }

    return ret;
}

int main() 
{
    std::string s1 = "aabcccccaaaa";
    std::string s2 = "ple";
    std::string s3 = "ppllee";
    std::string s4 = "popollllllllllllllllllllllllee";

    std::cout << s1 << ": " << StringCompression(s1) << std::endl;
    std::cout << s2 << ": " << StringCompression(s2) << std::endl;
    std::cout << s3 << ": " << StringCompression(s3) << std::endl;
    std::cout << s4 << ": " << StringCompression(s4) << std::endl;

    return 0;
}