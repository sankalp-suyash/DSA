class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> arr;
        int n = s.size();
        int temp = INT_MAX;
        int cnt = 0;
        string ans;

        for (int i = 0; i < n; i++) {
            string s2;
            for (int j = i; j < n; j++) {
                if (s[j] == '1') {
                    cnt++;
                }
                if (cnt <= k) {
                    s2 += s[j];
                }
                if (cnt == k) {
                    arr.push_back(s2);
                    int n2 = s2.size();
                    temp = min(temp, n2);
                }
            }
            cnt = 0;
        }

        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i].size() == temp) {
                ans += arr[i];
                break;
            }
        }
        return ans;
    }
};