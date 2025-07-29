class Solution {
public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = nextSmaller(arr);
        vector<int> pse = prevSmaller(arr);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i] * (nse[i] - pse[i] - 1));
        }
        return maxi;
    }

    // This is the Maximal Rectangle function.

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '1') {
                    sum += 1;
                } else {
                    sum = 0;
                }
                ans[i][j] = sum;
            }
        }

        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, largestRectangleArea(ans[i]));
        }

        return maxArea;
    }
};