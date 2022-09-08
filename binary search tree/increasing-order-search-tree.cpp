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
class LL {
public:
    TreeNode* head;
    TreeNode* tail;
};
class Solution {
public:
    LL helper(TreeNode* root) {
        LL l;
        if (root == NULL) {
            l.head = l.tail = NULL;
            return l;
        }
        if (root->left == NULL and root->right == NULL) {
            l.head = l.tail = root;
            return l;
        }
        else if (root->right == NULL and root->left != NULL) {
            LL left = helper(root->left);
            left.tail->right = root;
            root->left = NULL;
            l.head = left.head;
            l.tail = root;
            return l;
        }
        else if (root->left == NULL and root->right != NULL) {
            LL right = helper(root->right);
            root->right = right.head;
            root->left = NULL;
            l.head = root;
            l.tail = right.tail;
            return l;
        }
        LL left = helper(root->left);
        LL right = helper(root->right);
        left.tail->right = root;
        root->right = right.head;
        root->left = NULL;
        l.head = left.head;
        l.tail = right.tail;
        return l;
    }
    TreeNode* increasingBST(TreeNode* root) {
        LL pair = helper(root);
        return pair.head;
    }
};