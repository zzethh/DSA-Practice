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
    TreeNode* prev = NULL;
    void helper(TreeNode* root, vector<TreeNode*> &v) {
        if (root == NULL) {
            return;
        }
        helper(root->left, v);
        if (prev != NULL and prev->val > root->val) {
            if (v.empty()) {
                v.push_back(prev);
                v.push_back(root);
            } else {
                v.push_back(root);
            }
        }
        prev = root;
        helper(root->right, v);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        helper(root, v);
        if (v.size() == 2) {
            // int temp=v[0]->val;
            // v[0]->val=v[1]->val;
            // v[1]->val=temp;
            swap(v[0]->val, v[1]->val);
        } else if (v.size() > 2) {
            // int temp=v[0]->val;
            // v[0]->val=v[2]->val;
            // v[2]->val=temp;
            swap(v[0]->val, v[2]->val);
        }

    }
};