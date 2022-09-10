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
    void traversal(TreeNode* root, vector<int> &v) {
        if (root == NULL) {
            return;
        }
        traversal(root->left, v);
        v.push_back(root->val);
        traversal(root->right, v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        traversal(root1, v1);
        traversal(root2, v2);
        vector<int> temp(v1.size() + v2.size());
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < v1.size() and j < v2.size()) {
            if (v1[i] < v2[j]) {
                temp[k] = (v1[i]);
                k++;
                i++;
            }
            else {
                temp[k] = (v2[j]);
                k++;
                j++;
            }
        }

        while (i < v1.size()) {
            temp[k] = (v1[i++]);
            k++;
        }

        while (j < v2.size()) {
            temp[k] = (v2[j++]);
            k++;
        }

        return temp;
    }
};