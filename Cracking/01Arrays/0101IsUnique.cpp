#include <vector>
#include <unordered_set>
#include <iostream>

bool isUnique(const std::string &s) 
{
    std::unordered_set<char> uset;

    for(int ii = 0; ii < s.length(); ++ii) {
        char c = s[ii];
        auto res = uset.insert(c);
        if(!res.second) {
            return false;
        }
    }

    return true;
}

bool isUniqueLongVector(const std::string &s) 
{
    std::vector<int> v(128); //bitset

    for(int ii = 0; ii < s.length(); ++ii) {
        int x = s[ii];
        auto res = v[x]++;
        if(v[x] > 1) {
            return false;
        }
    }

    return true;
}

void printUnique(const std::string &s)
{
    if(isUnique(s)) {
        std::cout << s << " is Unique." << std::endl;
    } else {
        std::cout << s << " has a repeated letter." << std::endl;
    }
}

int main() 
{
    std::string s = "bondia";
    printUnique(s);

    s = "bondiaa";
    printUnique(s);

    return 0;
}