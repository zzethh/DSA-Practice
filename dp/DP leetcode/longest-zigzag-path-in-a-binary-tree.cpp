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
    int maxi = 0;
    void helper(TreeNode* root, bool dir, int len) {
        if (root == NULL) return;
        maxi = max(maxi, len);
        if (!dir) {
            helper(root->left, dir, 1);
            helper(root->right, !dir, len + 1);
        }
        else {
            helper(root->left, !dir, len + 1);
            helper(root->right, dir, 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        helper(root->left, 0, 1);
        helper(root->right, 1, 1);
        return maxi;
    }
};