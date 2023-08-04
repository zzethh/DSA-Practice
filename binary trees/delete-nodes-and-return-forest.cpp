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
    vector<TreeNode*> v;
    set<int> s;
    TreeNode* helper(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        if (s.find(root->val) != s.end()) {
            TreeNode* left = helper(root->left);
            TreeNode* right = helper(root->right);
            if (left != NULL) v.push_back(left);
            if (right != NULL) v.push_back(right);
            return NULL;
        }
        root->left = helper(root->left);
        root->right = helper(root->right);
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto x : to_delete) {
            s.insert(x);
        }
        TreeNode* x = helper(root);
        if (x != NULL) v.push_back(x);
        return v;
    }
};