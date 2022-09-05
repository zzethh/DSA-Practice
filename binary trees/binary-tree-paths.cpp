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
    void traversal(TreeNode* root, vector<string> &v, string s) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL and root->right == NULL) {
            s = s + to_string(root->val);
            v.push_back(s);
        }
        s = s + to_string(root->val) + "->";
        traversal(root->left, v, s);
        traversal(root->right, v, s);

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        string s = "";
        traversal(root, v, s);
        return v;
    }
};