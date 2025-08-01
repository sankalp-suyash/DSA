class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count;
        int left = 0, maxLen = 0;

        for (int right = 0; right < n; ++right) {
            count[nums[right]]++;
            while (count.size() > 2) {
                count[nums[left]]--;
                if (count[nums[left]] == 0) {
                    count.erase(nums[left]);
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};