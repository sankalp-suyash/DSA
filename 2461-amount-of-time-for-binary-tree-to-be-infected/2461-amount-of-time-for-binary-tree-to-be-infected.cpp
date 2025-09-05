/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    void markParents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

    TreeNode* findStart(TreeNode* root, int start) {
        if (!root)
            return nullptr;
        if (root->val == start)
            return root;
        TreeNode* left = findStart(root->left, start);
        if (left)
            return left;
        return findStart(root->right, start);
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track);

        TreeNode* startNode = findStart(root, start);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(startNode);
        visited[startNode] = true;

        int minutes = -1; // starts from -1 because first loop adds +1

        while (!q.empty()) {
            int size = q.size();
            minutes++;
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();

                if (current->left && !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if (parent_track[current] && !visited[parent_track[current]]) {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }

        return minutes;
    }
};
