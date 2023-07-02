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
    int minswaps(vector<int> arr) {
        vector<pair<int, int>> a;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            a.push_back({arr[i], i});
        }

        sort(a.begin(), a.end());
        vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int oldidx = a[i].second;
            if (vis[i] == true or oldidx == i) {
                continue;
            }

            int cycle = 0;
            int node = i;
            while (vis[node] != true) {
                vis[node] = true;
                node = a[node].second;
                cycle += 1;
            }
            ans += cycle - 1;
        }
        return ans;
    }
    void helper(TreeNode* root, map<int, vector<int>> &m, int l) {
        if (root == NULL) {
            return;
        }
        m[l].push_back(root->val);
        helper(root->left, m, l + 1);
        helper(root->right, m, l + 1);
    }
    int minimumOperations(TreeNode* root) {
        map<int, vector<int>> m;
        helper(root, m, 0);
        int ans = 0;
        for (auto x : m) {
            ans += minswaps(m[x.first]);
        }
        return ans;
    }
};