class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int lsum = 0, rsum = 0, maxSum = 0;

        for (int i = 0; i < k; i++) {
            lsum += nums[i];
        }
        maxSum = lsum;

        for (int i = 1; i <= k; i++) {
            lsum -= nums[k - i];
            rsum += nums[n - i];
            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum;
    }
};