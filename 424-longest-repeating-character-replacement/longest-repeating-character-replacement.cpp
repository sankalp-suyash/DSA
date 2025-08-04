class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0;
        int r = 0;
        int maxLen = 0;
        int maxFreq = 0;
        vector<int> nums(26, 0);

        while (r < n) {
            nums[s[r] - 'A']++;
            maxFreq = max(maxFreq, nums[s[r] - 'A']);

            while ((r - l + 1) - maxFreq > k) {
                nums[s[l] - 'A']--;
                maxFreq = 0;
                for (int i = 0; i < 26; i++) {
                    maxFreq = max(maxFreq, nums[i]);
                }
                l = l + 1;
            }
            if ((r - l + 1) - maxFreq <= k) {
                maxLen = max(maxLen, (r - l + 1));
            }
            r++;
        }
        return maxLen;
    }
};