class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int i : nums) {
            mp[i]++;
        }

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            int maxFreq = -1;
            int bestKey = 0;

            for (auto& it : mp) {
                if (it.second > maxFreq) {
                    maxFreq = it.second;
                    bestKey = it.first;
                }
            }
            ans.push_back(bestKey);
            mp[bestKey] = -1;
        }

        return ans;
    }
};