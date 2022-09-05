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
    int search(vector<int> v, int start, int end, int target) {
        for (int i = start; i <= end; i++) {
            if (v[i] == target) {
                return i;
            }
        }
        return -1;
    }

    int i = 0;

    TreeNode* build(vector<int> preorder, vector<int> inorder, int start, int end) {
        // static int i=0;
        if (start > end) {
            return NULL;
        }
        int element = preorder[i];
        i++;
        TreeNode* curr = new TreeNode(element);
        if (start == end) {
            return curr;
        }
        int pos = search(inorder, start, end, element);
        curr->left = build(preorder, inorder, start, pos - 1);
        curr->right = build(preorder, inorder, pos + 1, end);
        return curr;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 1) {
            return new TreeNode(preorder[0]);
        }
        TreeNode* root = build(preorder, inorder, 0, preorder.size() - 1);
        return root;
    }
};