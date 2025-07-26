class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // step 1 -> make a mapping to next greater for nums2.
        // this below code till before step2 calculates the next greater of nums2.
        unordered_map<int, int> mp;
        stack<int> st;
        
        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(st.size() > 0 && st.top() <= nums2[i]) {
                st.pop();
            }
            if(st.empty()) {
                mp[nums2[i]] = -1;
            }
            else {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        // step 2 -> iterate in nums1 and see the next greater from the nums2 map
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};