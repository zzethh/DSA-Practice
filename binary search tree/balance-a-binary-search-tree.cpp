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
    void help1(TreeNode* root, vector<int> &v) {
        if (root == NULL) {
            return;
        }
        help1(root->left, v);
        v.push_back(root->val);
        help1(root->right, v);
    }

    TreeNode* help2(vector<int> v, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode* n = new TreeNode(v[mid]);
        if (start == end) {
            return n;
        }
        n->left = help2(v, start, mid - 1);
        n->right = help2(v, mid + 1, end);
        return n;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        help1(root, v);
        return help2(v, 0, v.size() - 1);
    }
};