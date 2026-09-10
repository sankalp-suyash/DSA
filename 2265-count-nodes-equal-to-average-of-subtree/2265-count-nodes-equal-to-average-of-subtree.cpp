class Solution {
    int totalCount = 0;

    int findSum(TreeNode* root, int& count) {
        if (root == NULL) {
            return 0;
        }
        count++;
        int leftSum = findSum(root->left, count);
        int rightSum = findSum(root->right, count);
        return leftSum + rightSum + root->val;
    }

    void solve(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        int count = 0;
        int sum = findSum(root, count);
        if (root->val == (sum / count)) {
            totalCount++;
        }

        solve(root->left);
        solve(root->right);
    }

public:
    int averageOfSubtree(TreeNode* root) {
        totalCount = 0;
        solve(root);
        return totalCount;
    }
};