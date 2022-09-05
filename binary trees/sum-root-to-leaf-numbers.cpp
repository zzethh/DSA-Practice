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
    void sum(TreeNode* root, vector<int> &v, long int number) {
        if (root == NULL) {
            return;
        }
        if (!root->left and !root->right) {
            number = number * 10 + root->val;
            v.push_back(number);
        }
        number = number * 10 + root->val;
        sum(root->left, v, number);
        sum(root->right, v, number);
    }
    int sumNumbers(TreeNode* root) {
        vector<int> v;
        sum(root, v, 0);
        int sum = 0;
        for (auto x : v) {
            sum = sum + x;
        }
        return sum;
    }
};