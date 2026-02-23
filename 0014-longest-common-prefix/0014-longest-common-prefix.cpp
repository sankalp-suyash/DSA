class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string ans = "";
        string pref = s[0];
        for (int i = 1; i < s.size(); i++) {
            while (s[i].find(pref) != 0) {
                pref = pref.substr(0, pref.length() - 1);
                if (pref.empty()) {
                    return "";
                }
            }
        }
        return pref;
    }
};