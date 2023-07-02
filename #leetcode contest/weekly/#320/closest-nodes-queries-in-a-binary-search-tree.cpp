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
    vector<int> v;
    void helper(TreeNode* root) {
        if (root == NULL) return;
        helper(root->left);
        v.push_back(root->val);
        helper(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        helper(root);
        vector<vector<int>> ans;
        for (auto x : queries) {
            int lidx = lower_bound(v.begin(), v.end(), x) - v.begin();
            int uidx = upper_bound(v.begin(), v.end(), x) - v.begin();
            if (lidx != v.size() and v[lidx] == x) ans.push_back({x, x});
            else {
                if (lidx == 0 and uidx == v.size()) ans.push_back({ -1, -1});
                else if (lidx == 0) ans.push_back({ -1, v[uidx]});
                else if (uidx == v.size()) ans.push_back({v[lidx - 1], -1});
                else ans.push_back({v[lidx - 1], v[uidx]});
            }
        }
        return ans;
    }
};