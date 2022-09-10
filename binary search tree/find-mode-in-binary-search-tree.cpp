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
    int prev = INT_MIN;
    int curr = INT_MIN;
    int maxtillnow = INT_MIN;
    void helper(TreeNode* root, vector<int> &v) {
        if (root == NULL) {
            return;
        }
        helper(root->left, v);


        if (root->val == prev) {
            curr++;
        }

        else if (prev != root->val) {
            curr = 1;
        }

        if (curr > maxtillnow) {
            v.clear();
            v.push_back(root->val);
            maxtillnow = curr;
        }

        else if (curr == maxtillnow) {
            v.push_back(root->val);
        }

        prev = root->val;
        helper(root->right, v);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        helper(root, v);
        return v;
    }
};