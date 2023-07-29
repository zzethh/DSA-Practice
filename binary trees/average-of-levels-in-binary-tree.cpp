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
    map<int, vector<int>> m;
    void helper(TreeNode* root, int l) {
        if (root == NULL) return;
        m[l].push_back(root->val);
        helper(root->left, l + 1);
        helper(root->right, l + 1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        helper(root, 0);
        vector<double> ans;
        for (auto x : m) {
            double sum = 0;
            for (auto y : x.second) {
                sum += y;
            }
            double sz = x.second.size();
            ans.push_back((1.0 * sum) / sz);
        }
        return ans;
    }
};