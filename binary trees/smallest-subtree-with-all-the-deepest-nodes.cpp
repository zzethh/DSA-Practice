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
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    TreeNode* helper(TreeNode* root) {
        int left = height(root->left);
        int right = height(root->right);
        if (left == right) return root;
        if (left > right) return helper(root->left);
        return helper(root->right);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return helper(root);
    }
};