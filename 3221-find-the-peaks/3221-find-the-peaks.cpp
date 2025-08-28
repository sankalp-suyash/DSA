class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> peaks;
        int n = (int)mountain.size();
        for (int i = 1; i + 1 < n; ++i) {
            if (mountain[i] > mountain[i - 1] &&
                mountain[i] > mountain[i + 1]) {
                peaks.push_back(i);
            }
        }
        return peaks;
    }
};