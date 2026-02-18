class Solution {
public:
    int getSum(int a, int b) {
        int nums[] = {a,b};
        return accumulate(begin(nums), end(nums), 0);
    }
};