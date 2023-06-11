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
    int i = 0;
    int search(vector<int> &inorder, int s, int e, int curr) {
        for (int j = s; j <= e; j++) {
            if (inorder[j] == curr) {
                return j;
            }
        }
        return 0;
    }
    TreeNode* helper(vector<int> &inorder, vector<int> &preorder, int s, int e) {
        if (s > e) return NULL;
        int curr = preorder[i];
        i++;
        TreeNode* node = new TreeNode(curr);
        if (s == e) return node;
        int pos = search(inorder, s, e, curr);
        node->left = helper(inorder, preorder, s, pos - 1);
        node->right = helper(inorder, preorder, pos + 1, e);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder.begin(), preorder.end());
        sort(inorder.begin(), inorder.end());
        return helper(inorder, preorder, 0, preorder.size() - 1);

    }
};