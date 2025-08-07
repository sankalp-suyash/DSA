class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, count = 0;
        unordered_map<int, int> mp;

        for (int r = 0; r < n; ++r) {
            mp[nums[r]]++;

            while (mp.size() > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }

            count += r - l + 1;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
};