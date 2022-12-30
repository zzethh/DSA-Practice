/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  vector<int> helper(TreeNode* root,int target,vector<int> v){
//      v.push_back(root->val);
//      if(root->val==target){
//          return v;
//      }
//      if(root->left!=NULL) return helper(root->left,target,v);
//      if(root->right!=NULL) return helper(root->right,target,v);
//  }
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

vector<int> Solution::solve(TreeNode* A, int B) {
	vector<int> v;
	vector<int> ans;
	helper(A, B, v, ans);
	return ans;
}
