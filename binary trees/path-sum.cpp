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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL and root->right == NULL and targetSum == root->val) {
            return true;
        }
        targetSum = targetSum - (root->val);
        bool left = hasPathSum(root->left, targetSum);
        bool right = hasPathSum(root->right, targetSum);
        // if(left){
        //     return true;
        // }
        // if(right){
        //     return true;
        // }
        // return false;
        return right or left;
    }
};