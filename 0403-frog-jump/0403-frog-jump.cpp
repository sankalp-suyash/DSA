class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    int t[2001][2001];

    int solve(vector<int>& stones, int curr_stoneIdx, int prevJump) {
        if (curr_stoneIdx == n - 1) {
            return true;
        }
        if(t[curr_stoneIdx][prevJump] != -1) {
            return t[curr_stoneIdx][prevJump];
        }
        bool result = false;
        for (int nj = prevJump - 1; nj <= prevJump + 1; nj++) {
            if (nj > 0) {
                int nextStone = stones[curr_stoneIdx] + nj;
                if (mp.find(nextStone) != mp.end()) {
                    result = result || solve(stones,mp[nextStone], nj);
                }
            }
        }
        return t[curr_stoneIdx][prevJump] = result;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();

        if (stones[1] != 1) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        memset(t, -1, sizeof(t));
        return solve(stones, 0, 0);
    }
};