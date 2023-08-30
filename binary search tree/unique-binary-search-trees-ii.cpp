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
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> v;
        if (start > end) {
            return {NULL};
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = helper(start, i - 1);
            vector<TreeNode*> right = helper(i + 1, end);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* n = new TreeNode(i);
                    n->left = l;
                    n->right = r;
                    v.push_back(n);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};