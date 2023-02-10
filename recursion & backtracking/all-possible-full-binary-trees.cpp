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

    vector<TreeNode*> helper(int n) {
        // if(n<1){
        //     return NULL;
        // }
        vector<TreeNode*> v;

        if (n == 1) {
            TreeNode* nod = new TreeNode(0);
            v.push_back(nod);
            return v;
        }

        for (int i = 1; i < n; i = i + 2) {
            vector<TreeNode*> left = helper(i);
            vector<TreeNode*> right = helper(n - i - 1);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    v.push_back(root);
                }
            }

        }


        return v;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> v;
        v = helper(n);
        return v;
    }
};