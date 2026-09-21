class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            int char_weight = 'z' - s[i] + 1;
            ans += (i + 1) * char_weight;
        }
        return ans;
    }
};