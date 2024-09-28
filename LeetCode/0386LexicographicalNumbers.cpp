class Solution {
public:
    static vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        int x = 1;
        for(int ii = 0; ii < n; ++ii) {
            ret[ii] = x;
            if((x * 10) > n) {
                if(x == n) {
                    x /= 10;
                }

                ++x;
                while((x % 10) == 0) {
                    x /= 10;
                }
            } else { 
                x *= 10;
            }          
        }
        return ret;
    }
};
