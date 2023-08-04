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
    unordered_map<int, int> m;
    int cnt = 0;
    int helper(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int sum = root->val + helper(root->left) + helper(root->right);
        m[sum]++;
        cnt = max(cnt, m[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        vector<int> ans;
        for (auto x : m) {
            if (x.second == cnt) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};