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
class node {
public:
    int maxsum, mini, maxi;
    node(int mini, int maxi, int maxsum) {
        this->maxi = maxi;
        this->mini = mini;
        this->maxsum = maxsum;
    }
};
class Solution {
public:
    int ans = INT_MIN;
    node helper(TreeNode* root) {
        if (root == NULL) {
            node n(INT_MAX, INT_MIN, 0);
            return n;
        }

        node left = helper(root->left);
        node right = helper(root->right);

        if (left.maxi < root->val and root->val < right.mini) {
            ans = max(ans, root->val + left.maxsum + right.maxsum);
            return node(min(root->val, left.mini), max(root->val, right.maxi), left.maxsum + right.maxsum + root->val);
        }
        ans = max(ans, max(left.maxsum, right.maxsum));
        return node(INT_MIN, INT_MAX, max(left.maxsum, right.maxsum));
    }
    int maxSumBST(TreeNode* root) {
        helper(root).maxsum;
        if (ans < 0) return 0;
        return ans;
    }
};