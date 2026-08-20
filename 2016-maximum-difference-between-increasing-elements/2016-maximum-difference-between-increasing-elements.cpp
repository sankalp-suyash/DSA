class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int diff = -1;

        while (j < nums.size()) {
            if (nums[i] < nums[j]) {
                diff = max(diff, nums[j] - nums[i]);
            } else {
                i = j;
            }
            j++;
        }

        return diff;
    }
};