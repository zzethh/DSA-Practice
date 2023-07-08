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
        return max(height(root->left), height(root->right)) + 1;
    }
    int helper(TreeNode* root) {
        if (root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        int currdia = lh + rh;
        return max(currdia, max(helper(root->left), helper(root->right)));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root);
    }
};