#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void helper(TreeNode<int> *root, vector<int> &v) {
    if (root == NULL) return;
    helper(root->left, v);
    v.push_back(root->val);
    helper(root->right, v);
}
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    vector<int> v;
    helper(root, v);
    int pre;
    for (auto x : v) {
        if (x <= X) {
            pre = x;
        }
    }
    return pre;
}