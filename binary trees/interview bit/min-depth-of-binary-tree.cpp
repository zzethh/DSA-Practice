/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* root, int &mini, int cnt) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL and root->right == NULL) {
        cnt++;
        mini = min(mini, cnt);
        return ;
    }
    cnt++;
    helper(root->left, mini, cnt);
    helper(root->right, mini, cnt);
}
int Solution::minDepth(TreeNode* A) {
    int cnt = 0;
    int mini = INT_MAX;
    helper(A, mini, cnt);
    return mini;
}
