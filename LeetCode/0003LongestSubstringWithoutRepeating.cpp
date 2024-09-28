    int lengthOfLongestSubstring(string s) {
        int max = -1;
        int first = 0;
        unordered_set<char> uset;

        for(int ii = 0; ii < s.size(); ++ii) {
            char c = s[ii];
            if(!uset.count(c)) {
                uset.insert(c);
                if(ii - first > max) {
                    max = ii - first;
                }
            } else { // exists.
                while(s[first] != c) {
                    uset.erase(s[first++]);
                }
                ++first;
            }
        }
        return max + 1;
    }
