class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int pro = 1;
        int zeroCount = 0;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                pro *= nums[i];
            } else {
                zeroCount++;
            }
        }

        if (zeroCount > 1) {
            return vector<int>(n, 0);
        }

        for (int i = 0; i < n; i++) {
            if (zeroCount > 0) {
                ans[i] = (nums[i] == 0) ? pro : 0;
            } else {
                ans[i] = pro / nums[i];
            }
        }

        return ans;
    }
};