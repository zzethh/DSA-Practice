/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int prev = -1;
    void helper(TreeNode* root, int &diff) {
        if (root == NULL) {
            return;
        }
        helper(root->left, diff);
        if (root->val - prev <= diff and prev >= 0) {
            diff = root->val - prev;
        }
        prev = root->val;
        helper(root->right, diff);
    }
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        helper(root, diff);
        return diff;
    }
};