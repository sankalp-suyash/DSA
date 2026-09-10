class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
        if (s.length() != t.length())
            return false;

        int freq[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int count : freq) {
            if (count != 0)
                return false;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int n = strs.size();
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;

            vector<string> group;
            group.push_back(strs[i]);
            visited[i] = true;

            for (int j = i + 1; j < n; j++) {
                if (!visited[j] && isAnagram(strs[i], strs[j])) {
                    group.push_back(strs[j]);
                    visited[j] = true;
                }
            }

            result.push_back(group);
        }

        return result;
    }
};