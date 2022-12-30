/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void kdist(TreeNode* root, int k, vector<int> &v) {
    if (root == NULL) {
        return ;
    }
    if (k == 0) v.push_back(root->val);
    kdist(root->left, k - 1, v);
    kdist(root->right, k - 1, v);
}
int helper(TreeNode* root, int target, int k, vector<int> &v) {
    if (root == NULL) {
        return -1;
    }
    if (root->val == target) {
        kdist(root, k, v);
        return 0;
    }
    int ld = helper(root->left, target, k, v);
    int rd = helper(root->right, target, k, v);
    if (ld != -1) {
        if (1 + ld == k) v.push_back(root->val);
        else {
            kdist(root->right, k - ld - 2, v);
        }

        return ld + 1;
    }
    else if (rd != -1) {
        if (1 + rd == k) v.push_back(root->val);
        else {
            kdist(root->left, k - rd - 2, v);
        }

        return rd + 1;
    }

    return -1;
}
vector<int> Solution::distanceK(TreeNode* A, int B, int C) {
    vector<int> v;
    helper(A, B, C, v);
    return v;
}
