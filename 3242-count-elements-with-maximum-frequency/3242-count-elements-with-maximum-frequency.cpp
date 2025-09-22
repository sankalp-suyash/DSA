class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        int maxFreq = 0;
        for (auto& [num, freq] : mp) {
            maxFreq = max(maxFreq, freq);
        }
        int total = 0;
        for (auto& [num, freq] : mp) {
            if (freq == maxFreq) {
                total += freq;
            }
        }
        return total;
    }
};