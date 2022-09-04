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
    void traversal(TreeNode* root, map<int, vector<int>> &m, int k) {
        if (root == NULL) {
            return;
        }
        m[k].push_back(root->val);
        traversal(root->left, m, k + 1);
        traversal(root->right, m, k + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int, vector<int>> m;
        vector<vector<int>> v;
        traversal(root, m, 0);
        for (auto x : m) {
            vector<int> temp;
            for (auto y : x.second) {
                temp.push_back(y);
            }
            v.push_back(temp);
        }
        return v;
    }
};