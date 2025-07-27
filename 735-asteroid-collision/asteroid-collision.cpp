class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            if (a > 0)
                st.push(a);
            else {
                while (!st.empty() && st.top() > 0 && st.top() < -a)
                    st.pop();

                if (!st.empty() && st.top() == -a)
                    st.pop();
                else if (st.empty() || st.top() < 0)
                    st.push(a);
            }
        }

        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};