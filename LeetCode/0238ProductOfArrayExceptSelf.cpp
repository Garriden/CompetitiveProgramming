class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size());
        if(nums.size() < 2) {
            return ret;
        }
        vector<int> prefix(nums.size());
        vector<int> sufix(nums.size());

        prefix[0] = nums[0];
        sufix[nums.size()-1] = nums[nums.size()-1];
        for(int ii = 1; ii < nums.size(); ++ii) {
            prefix[ii] = prefix[ii-1] * nums[ii];
            sufix[nums.size()-1-ii] = sufix[nums.size()-ii] * nums[nums.size()-1-ii];
        }

        ret[0] = sufix[1];
        ret[nums.size()-1] = prefix[nums.size()-2];
        for(int ii = 1; ii < nums.size()-1; ++ii) {
            ret[ii] = prefix[ii-1] * sufix[ii+1];
        }
        
        return ret;
    }
};
