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
    void travel(TreeNode* root, int d, map<int, vector<int>> &m) {
        if (root == NULL) {
            return;
        }
        m[d].push_back(root->val);
        travel(root->right, d + 1, m);
        travel(root->left, d - 1, m);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int distance = 0;
        map<int, vector<int>> m;
        vector<vector<int>> v;
        travel(root, distance, m);
        for (auto x : m) {
            v.push_back(x.second);
        }
        return v;
    }
};