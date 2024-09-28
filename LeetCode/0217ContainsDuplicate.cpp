class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        for(int ii = 0; ii < nums.size(); ++ii) {
            if(m.count(nums[ii])) {
                return true;
            } else {
                m.insert(nums[ii]);
            }
        }
        return false;
    }
};
