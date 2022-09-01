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

node* buildTree(vector<int> postorder, vector<int> inorder, int start, int end) {
	static int i = 4;
	if (start > end) {
		return NULL;
	}
	int curr = postorder[i];
	i--;
	node* n = new node(curr);
	if (start == end) {
		return n;
	}
	int pos = search(inorder, start, end, curr);
	n->right = buildTree(postorder, inorder, pos + 1, end);
	n->left = buildTree(postorder, inorder, start, pos - 1);
	return n;
}




int main() {
	vector<int> postorder = {4, 2, 5, 3, 1};
	vector<int> inorder = {4, 2, 1, 5, 3};
	node* root1 = buildTree(postorder, inorder, 0, postorder.size() - 1);
	inOrder(root1);

	return 0;
}

