/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* root, int k, map<int, bool> &vis, vector<int> &ans) {
    if (root == NULL) return;
    if (!vis[k]) ans.push_back(root->val);
    vis[k] = 1;
    helper(root->right, k - 1, vis, ans);
    helper(root->left, k - 1, vis, ans);
}
vector<int> Solution::solve(TreeNode* A) {
    map<int, bool> visited;
    vector<int> ans;
    helper(A, 0, visited, ans);
    return ans;
}
