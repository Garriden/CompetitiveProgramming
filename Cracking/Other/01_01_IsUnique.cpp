#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

bool isUnique(const string &str) 
{
    unordered_set<char> set;
    
    for(int ii = 0; ii < str.size(); ++ii) {
        if(set.count(str[ii])) {
            return false;
        } else {
            set.insert(str[ii]);
        }
    }
    
    return true;
}

int main(){
		vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
		for (auto word : words)
		{
			cout << word << string(": ") << boolalpha << isUnique(word) <<endl;
		}

		return 0;
}
