class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int maxiArea = 0;

        while (l < r) {
            int width = r - l;
            int currArea = width * min(height[l], height[r]);
            maxiArea = max(maxiArea, currArea);
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return maxiArea;
    }
};