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
    void traversal(TreeNode* root, int &sum, bool x) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL and root->right == NULL and x == 0) {
            sum = sum + root->val;
            return;
        }
        traversal(root->left, sum, 0);
        traversal(root->right, sum, 1);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        traversal(root, sum, 1);
        return sum;
    }
};