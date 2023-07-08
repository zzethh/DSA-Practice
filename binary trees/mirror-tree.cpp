bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL or q == NULL) {
        return false;
    }
    if (p->val == q->val && isSameTree(p->left, q->right) and isSameTree(p->right, q->left)) {
        return true;
    }
    return false;
}