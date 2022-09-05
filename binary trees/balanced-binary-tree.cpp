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
class pairxx {
public:
    int height;
    bool isbalanced;
};

class Solution {
public:
    pairxx balance(TreeNode* root) {
        pairxx p;
        if (root == NULL) {
            p.height = 0;
            p.isbalanced = true;
            return p;
        }
        auto l = balance(root->left);
        auto r = balance(root->right);
        p.height = max(l.height, r.height) + 1;
        if (abs(l.height - r.height) <= 1 and l.isbalanced == true and r.isbalanced == true) {
            p.isbalanced = true;
        } else {
            p.isbalanced = false;
        }
        return p;
    }

    bool isBalanced(TreeNode* root) {
        pairxx p = balance(root);
        return p.isbalanced;
    }
};