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
    int sum = 0;
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        int l = height(root->left);
        int r = height(root->right);
        return 1 + max(l, r);
    }
    void helper(TreeNode* root, int k, int level) {
        if (root == NULL) return;
        if (root->left == NULL and root->right == NULL and k == level) {
            sum += root->val;
            return;
        }
        helper(root->left, k + 1, level);
        helper(root->right, k + 1, level);
    }
    int deepestLeavesSum(TreeNode* root) {
        int level = height(root);
        helper(root, 1, level);
        return sum;
    }
};