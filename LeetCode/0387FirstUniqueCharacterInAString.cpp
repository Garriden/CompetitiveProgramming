class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> map;

        for(int ii = 0; ii < s.size(); ++ii) {
            map[s[ii]]++;
        }

        for(int ii = 0; ii < s.size(); ++ii) {
            if(map[s[ii]] == 1) return ii;
        }

        return -1;
    }
};
