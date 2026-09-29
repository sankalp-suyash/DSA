class Solution {
public:
    // Memoization technique

    int func(int steps, vector<int>& dp) {
        if (steps == 0) {
            return 1;
        }
        if (steps < 0) {
            return 0;
        }
        if (dp[steps] != -1) {
            return dp[steps];
        }
        int oneStepJump = func(steps - 1, dp);
        int twoStepJump = func(steps - 2, dp);

        dp[steps] = oneStepJump + twoStepJump;
        return dp[steps];
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return func(n, dp);
    }
};