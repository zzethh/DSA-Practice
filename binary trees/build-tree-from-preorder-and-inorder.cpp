#include<bits/stdc++.h>
using namespace std;


class node {
public:
	int data;
	node* left;
	node* right;
	node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};


void preOrder(node* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(node* root) {
	if (root == NULL) {
		return;
	}
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

int search(vector<int> inorder, int start, int end, int curr) {
	for (int i = start; i <= end; i++) {
		if (inorder[i] == curr) {
			return i;
		}
	}
	return -1;
}

node* buildTree(vector<int> preorder, vector<int> inorder, int start, int end) {
	static int idx = 0;
	if (start > end) {
		return NULL;
	}
	int curr = preorder[idx];
	idx++;
	node* n = new node(curr);
	if (start == end) {
		return n;
	}
	int pos = search(inorder, start, end, curr);
	n->left = buildTree(preorder, inorder, start, pos - 1);
	n->right = buildTree(preorder, inorder, pos + 1, end);
	return n;
}




int main() {
	vector<int> preorder = {1, 2, 4, 3, 5};
	vector<int> inorder = {4, 2, 1, 5, 3};
	node* root1 = buildTree(preorder, inorder, 0, preorder.size() - 1);
	inOrder(root1);

	return 0;
}

