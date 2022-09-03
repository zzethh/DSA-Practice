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


void levelOrder(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		auto element = q.front();
		q.pop();
		if (element == NULL and q.empty() == false) {
			cout << endl;
			q.push(NULL);
			continue;
		}
		if (element == NULL and q.empty() == true) {
			return;
		}
		cout << element->data << " ";
		if (element->left != NULL) {
			q.push(element->left);
		}
		if (element->right != NULL) {
			q.push(element->right);
		}
	}
}


// node* buildTree() {
// 	int d;
// 	cin >> d;
// 	if (d == -1) {
// 		return NULL;
// 	}
// 	node* n = new node(d);
// 	n->left = buildTree();
// 	n->right = buildTree();
// 	return n;
// }

node* levelOrderBuild() {
	int d;
	cin >> d;
	node* root = new node(d);
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node* current = q.front();
		q.pop();
		int c1, c2;
		cin >> c1 >> c2;
		if (c1 != -1) {
			current->left = new node(c1);
			q.push(current->left);
		}
		if (c2 != -1) {
			current->right = new node(c2);
			q.push(current->right);
		}
	}
	return root;
}

class pairxx {
public:
	int inc;
	int exc;
};

pairxx maxSubset(node* root) {
	pairxx p;
	if (root == NULL) {
		p.inc = 0;
		p.exc = 0;
		return p;
	}
	auto l = maxSubset(root->left);
	auto r = maxSubset(root->right);
	p.inc = root->data + l.exc + r.exc;
	p.exc = max(l.inc, l.exc) + max(r.inc, r.exc);
	return p;
}



int main() {
	node* root = levelOrderBuild();
	levelOrder(root);
	pairxx p = maxSubset(root);
	cout << endl << p.exc << " " << p.inc;
	return 0;
}

