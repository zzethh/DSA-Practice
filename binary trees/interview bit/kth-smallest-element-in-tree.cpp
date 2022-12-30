/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* root, vector<int> &v) {
    if (root == NULL) return;
    helper(root->left, v);
    v.push_back(root->val);
    helper(root->right, v);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    vector<int> v;
    helper(A, v);
    return v[B - 1];
}
