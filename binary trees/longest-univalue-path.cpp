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
    int maxi = -1;
    vector<int> helper(TreeNode* root) {
        if (root == NULL) return {0, 0};
        //if(root->left==NULL and root->right==NULL) return {1,1};
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        if (root->left and root->right and root->val == root->left->val and root->right->val == root->val) {
            maxi = max(maxi, left[1] + right[1] + 1);
            return {left[1] + right[1] + 1, max(left[1], right[1]) + 1};
        }
        else if (root->left and root->val == root->left->val) {
            maxi = max(maxi, left[1] + 1);
            return {left[1] + 1, left[1] + 1};
        }
        else if (root->right and root->right->val == root->val) {
            maxi = max(maxi, right[1] + 1);
            return {right[1] + 1, right[1] + 1};
        }
        maxi = max(maxi, 1);
        return {1, 1};
    }
    int longestUnivaluePath(TreeNode* root) {
        vector<int> v = helper(root);
        return maxi > 0 ? maxi - 1 : 0;
    }
};