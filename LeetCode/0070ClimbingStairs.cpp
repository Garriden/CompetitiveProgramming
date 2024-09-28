class Solution {
public:
    int climbStairs(int n) {
        int temp = 0;
        int unos = 1;
        int dos = 1;
        for(int ii = 0; ii < n-1; ++ii) {
            temp = unos;
            unos += dos;
            dos = temp;
        }

        return unos;
    }
};
