v/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* helper(TreeNode* root1, TreeNode* root2) {
	if (root1 == NULL and root2 == NULL) return NULL;
	//  if(root1->left==NULL){
	//      return root2->left;
	//  }
	//  if(root2->left==NULL){
	//      return root1->left;
	//  }
	//  if(root2->right==NULL){
	//      return root1->right;
	//  }
	//  if(root1->right==NULL){
	//      return root2->right;
	//  }
	if (root1 == NULL) return root2;
	if (root2 == NULL) return root1;
	TreeNode* root = new TreeNode(root1->val + root2->val);
	root->left = helper(root1->left, root2->left);
	root->right = helper(root1->right, root2->right);
	return root;
}
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
	TreeNode* root = helper(A, B);
	return root;
}
