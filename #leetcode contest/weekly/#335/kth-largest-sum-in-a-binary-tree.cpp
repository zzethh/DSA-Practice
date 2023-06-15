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
    void helper(TreeNode* root, int k, map<long long, vector<long long>> &m) {
        if (root == NULL) {
            return;
        }
        m[k].push_back(root->val);
        helper(root->left, k + 1, m);
        helper(root->right, k + 1, m);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        map<long long, vector<long long>> m;
        long long sum = 0;
        helper(root, 1, m);
        vector<long long> v;
        for (auto x : m) {
            sum = 0;
            for (auto y : x.second) {
                sum += y;
            }
            v.push_back(sum);
        }
        if (v.size() < k) return -1;
        sort(v.begin(), v.end(), greater());
        for (auto x : v) {
            cout << x << endl;
        }
        return v[k - 1];
    }
};