void solve(Node* root, vector<int> &ans, int l) {
    if (!root) return;
    if (ans.size() == l) {
        ans.push_back(root->data);
    }
    solve(root->left, ans, l + 1);
    solve(root->right, ans, l + 1);
}
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int>ans;
    solve(root, ans, 0);
    return ans;
}