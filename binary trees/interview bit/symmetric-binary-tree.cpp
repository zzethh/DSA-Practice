/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper1(TreeNode* root, vector<int> &v, vector<int> temp) {
    if (root == NULL) {
        v.push_back(0);
        return;
    }
    v.push_back(root->val);
    helper1(root->left, v, temp);
    helper1(root->right, v, temp);
}

void helper2(TreeNode* root, vector<int> &v, vector<int> temp) {
    if (root == NULL) {
        v.push_back(0);
        return;
    }
    v.push_back(root->val);
    helper2(root->right, v, temp);
    helper2(root->left, v, temp);
}

int Solution::isSymmetric(TreeNode* A) {
    vector<int> left;
    vector<int> right;
    vector<int> temp;
    helper1(A, left, temp);
    helper2(A, right, temp);
    int i = 0;
    int j = 0;
    while (i < left.size() and j < right.size()) {
        if (left[i] != right[i]) {
            return 0;
        }
        else {
            i++;
            j++;
        }
    }
    return 1;
}
