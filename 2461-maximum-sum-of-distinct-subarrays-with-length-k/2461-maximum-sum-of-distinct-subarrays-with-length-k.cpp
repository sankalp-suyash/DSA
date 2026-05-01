class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        long long sum = 0;
        long long maxi = 0; 

        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            freq[nums[j]]++;

            if (j - i + 1 > k) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0)
                    freq.erase(nums[i]);
                sum -= nums[i];
                i++;
            }

            if (j - i + 1 == k) {
                if (freq.size() == k) {
                    maxi = max(maxi, sum);
                }
            }
        }

        return maxi;
    }
};