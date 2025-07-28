class Solution {
public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
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
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
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
};
