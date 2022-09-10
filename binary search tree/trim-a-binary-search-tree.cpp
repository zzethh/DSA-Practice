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
    TreeNode* inorder(TreeNode* root) {
        TreeNode* temp = root;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == NULL) {
            return NULL;
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        if (root->val < low or root->val > high) {
            if (root->left == NULL and root->right == NULL) {
                return NULL;
            }
            else if (root->left == NULL and root->right != NULL) {
                root = root->right;
                return root;
            }
            else if (root->right == NULL and root->left != NULL) {
                root = root->left;
                return root;
            }
            TreeNode* temp = inorder(root->right);
            root->val = temp->val;
            root->right = trimBST(root->right, low, high);
        }
        return root;
    }
};