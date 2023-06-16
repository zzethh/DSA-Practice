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
    int maxLevelSum(TreeNode* root) {
        map<int, vector<int>> m;
        int maxi = INT_MIN;
        traversal(root, m, 1);
        int level = -1;
        for (auto x : m) {
            int sum = 0;
            for (auto y : x.second) {
                sum += y;
            }
            //cout<<sum<<endl;
            if (sum > maxi) {
                level = x.first;
                maxi = sum;
            }
        }
        return level;
    }
};