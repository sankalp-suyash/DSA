class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = 1;
        int maxProfit = 0;

        while (j < prices.size()) {
            if (prices[i] < prices[j]) {
                int currentProfit = prices[j] - prices[i];
                maxProfit = max(maxProfit, currentProfit);
            } else {
                i = j;
            }
            j++;
        }

        return maxProfit;
    }
};