class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = 10000;
        int profit = 0;

        for(int ii = 0; ii < prices.size(); ++ii) {
            if(prices[ii] < min) {
                min = prices[ii];
            }
            if((prices[ii] - min) > profit) {
                profit = (prices[ii] - min);
            }
        }
        return profit;
    }
};
