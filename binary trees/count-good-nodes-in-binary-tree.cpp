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
    void helper(TreeNode* root, int &cnt, int maxi) {
        if (root == NULL) return;
        if (root->val >= maxi) {
            cnt++;
        }
        int temp = maxi;
        maxi = max(maxi, root->val);
        helper(root->left, cnt, maxi);
        helper(root->right, cnt, maxi);
        maxi = temp;
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        int maxi = INT_MIN;
        helper(root, cnt, maxi);
        return cnt;
    }
};