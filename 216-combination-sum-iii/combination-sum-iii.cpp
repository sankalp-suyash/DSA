class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int> temp, int k, int n,
               int start) {
        if (k == 0 && n == 0) {
            ans.push_back(temp);
        }

        for (int i = start; i <= 9; i++) {
            if (i > n)
                break;

            temp.push_back(i);
            solve(ans, temp, k - 1, n - i, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(ans, temp, k, n, 1);
        return ans;
    }
};