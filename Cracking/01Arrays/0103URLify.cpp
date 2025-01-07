#include <iostream>

/*
Process thought:
  - Iterate?.
  - Split string, replace.
    Time complexity: O(n)
*/

std::string URLify(const std::string &s) 
{
    std::string aux = "";
    bool recentSpace = false;

    for(int ii = 0; ii < s.size(); ++ii) {
        if(s[ii] == ' ') {
            if(!recentSpace) {
                aux.push_back('%');
                aux.push_back('2');
                aux.push_back('0');
            }
            recentSpace = true;
        } else {
            aux.push_back(s[ii]);
            recentSpace = false;
        }
    }

    //Check last character
    if(aux[aux.size()-1] == '0' && aux[aux.size()-2] == '2' && aux[aux.size()-3] == '%') {
        aux.pop_back();
        aux.pop_back();
        aux.pop_back();
    }

    return aux;
}

int main() 
{
    std::string s1 = " b ond     ia   ";
    std::string out = URLify(s1);
    std::cout << out << std::endl;

    s1 = " Hola em dic Marc i sóc molt guapo. ";
    out = URLify(s1);
    std::cout << out << std::endl;

    return 0;
}