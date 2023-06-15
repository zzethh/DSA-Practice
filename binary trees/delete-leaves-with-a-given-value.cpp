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
    void helper(TreeNode* root, int target) {
        if (root == NULL) return;
        helper(root->left, target);
        helper(root->right, target);
        if (root->left and root->left->left == NULL and root->left->right == NULL and root->left->val == target) {
            root->left = NULL;
        }
        if (root->right and root->right->left == NULL and root->right->right == NULL and root->right->val == target) {
            root->right = NULL;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        helper(root, target);
        if (root->right == NULL and root->left == NULL and root->val == target) return NULL;
        return root;
    }
};