class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int a =  nums[i];
            int complement = target - a;
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};
            }
            hash[a] = i;
        }
        return {};
    }
};
