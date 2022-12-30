/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* root, int b, vector<int> v, vector<int> &ans) {
	if (root == NULL) return;
	v.push_back(root->val);
	if (root->val == b) {
		for (int i = 0; i < v.size(); i++) {
			ans.push_back(v[i]);
		}
		return;
	}
	helper(root->left, b, v, ans);
	helper(root->right, b, v, ans);
}

int Solution::lca(TreeNode* A, int B, int C) {
	vector<int> temp;
	vector<int> v1;
	vector<int> v2;
	helper(A, B, temp, v1);
	helper(A, C, temp, v2);
	int cnt = -1;
	//cout << v2[0];
	for (int i = 0; i < min(v2.size(), v1.size()); i++) {
		cnt = i;
		if (v1[i] != v2[i]) {
			cnt = i - 1;
			break;
		}
	}
	//cout<<v1[0]<<" ";
	if (cnt >= 0) return v1[cnt];
	return -1;
}
