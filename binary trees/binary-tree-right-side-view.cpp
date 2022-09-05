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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if (root == NULL) {
            return v;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            v.push_back(q.front()->val);
            for (int i = 0; i < size; i++) {
                auto front = q.front();
                q.pop();
                if (front->right != NULL) {
                    q.push(front->right);
                }
                if (front->left != NULL) {
                    q.push(front->left);
                }
            }
        }
        return v;
    }
};