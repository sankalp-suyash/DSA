class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(n);
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, candies[i]);
        }
        int num = maxi - extraCandies;
        for (int i = 0; i < n; i++) {
            if (candies[i] < num) {
                ans[i] = false;
            } else {
                ans[i] = true;
            }
        }
        return ans;
    }
};