/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//vector<vector<int>> ans;

void helper(TreeNode* root, int sum, vector<vector<int>> &ans, vector<int> v) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL and root->right == NULL) {
        v.push_back(root->val);
        if (root->val == sum) ans.push_back(v);
        return;
    }

    //sum=sum-root->val;
    v.push_back(root->val);
    helper(root->left, sum - root->val, ans, v);
    helper(root->right, sum - root->val, ans, v);
    return;

}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> ans;
    vector<int> v;
    helper(A, B, ans, v);
    return ans;
}
