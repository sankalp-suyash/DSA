class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countZero = 0;
        long long totalProductWithoutZero = 1;

        for (auto& i : nums) {
            if (i == 0) {
                countZero++;
            } else {
                totalProductWithoutZero *= i;
            }
        }

        vector<int> res(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            if (countZero == 0) {
                res[i] = totalProductWithoutZero / nums[i];
            } else if (countZero == 1) {
                if (nums[i] == 0) {
                    res[i] = totalProductWithoutZero;
                } else {
                    res[i] = 0;
                }
            } else {
                res[i] = 0;
            }
        }

        return res;
    }
};