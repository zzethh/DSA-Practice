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


// void preOrder(node* root) {
// 	if (root == NULL) {
// 		return;
// 	}
// 	cout << root->data << " ";
// 	preOrder(root->left);
// 	preOrder(root->right);
// }

// void inOrder(node* root) {
// 	if (root == NULL) {
// 		return;
// 	}
// 	inOrder(root->left);
// 	cout << root->data << " ";
// 	inOrder(root->right);
// }

// void postOrder(node* root) {
// 	if (root == NULL) {
// 		return;
// 	}
// 	postOrder(root->left);
// 	postOrder(root->right);
// 	cout << root->data << " ";
// }

// int search(vector<int> inorder, int start, int end, int curr) {
// 	for (int i = start; i <= end; i++) {
// 		if (inorder[i] == curr) {
// 			return i;
// 		}
// 	}
// 	return -1;
// }

// node* buildTree(vector<int> postorder, vector<int> inorder, int start, int end) {
// 	static int i = 4;
// 	if (start > end) {
// 		return NULL;
// 	}
// 	int curr = postorder[i];
// 	i--;
// 	node* n = new node(curr);
// 	if (start == end) {
// 		return n;
// 	}
// 	int pos = search(inorder, start, end, curr);
// 	n->right = buildTree(postorder, inorder, pos + 1, end);
// 	n->left = buildTree(postorder, inorder, start, pos - 1);
// 	return n;
// }


// void levelOrder(node* root) {
// 	queue<node*> q;
// 	q.push(root);
// 	q.push(NULL);
// 	while (!q.empty()) {
// 		auto element = q.front();
// 		q.pop();
// 		if (element == NULL and q.empty() == false) {
// 			cout << endl;
// 			q.push(NULL);
// 			continue;
// 		}
// 		if (element == NULL and q.empty() == true) {
// 			return;
// 		}
// 		cout << element->data << " ";
// 		if (element->left != NULL) {
// 			q.push(element->left);
// 		}
// 		if (element->right != NULL) {
// 			q.push(element->right);
// 		}
// 	}
// }

int countNode(node* root) {
	if (root == NULL) {
		return 0;
	}
	int cnt = countNode(root->left) + countNode(root->right) + 1;
	return cnt;
}

int sumNodes(node* root) {
	if (root == NULL) {
		return 0;
	}
	int cnt = sumNodes(root->left) + sumNodes(root->right) + root->data;
	return cnt;
}



int main() {
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);

	cout << countNode(root) << " " << sumNodes(root);



	return 0;
}

