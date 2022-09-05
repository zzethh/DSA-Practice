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

    TreeNode* build(vector<int> inorder, vector<int> postorder, int start, int end, int *idx) {
        if (start > end) {
            return NULL;
        }
        int element = postorder[*idx];
        (*idx)--;
        TreeNode* n = new TreeNode(element);
        if (start == end) {
            return n;
        }
        int pos = search(inorder, start, end, element);
        n->right = build(inorder, postorder, pos + 1, end, idx);
        n->left = build(inorder, postorder, start, pos - 1, idx);
        return n;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size() - 1;
        TreeNode* root = build(inorder, postorder, 0, postorder.size() - 1, &n);
        return root;
    }
};