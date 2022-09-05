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
    void traversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        invertTree(root->right);
        invertTree(root->left);
        TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

    TreeNode* invertTree(TreeNode* root) {
        traversal(root);
        return root;
    }
};