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

void inOrder(node* root) {
	if (root == NULL) {
		return;
	}
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

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

node* insertBST(node* root, int val) {
	if (root == NULL) {
		return new node(val);
	}
	if (val < root->data) {
		root->left = insertBST(root->left, val);
	} else {
		root->right = insertBST(root->right, val);
	}
	return root;
}

// node* search(node* root, int key) {
// 	if (root == NULL) {
// 		return NULL;
// 	}
// 	if (root->data == key) {
// 		return root;
// 	}
// 	if (root->data > key) {
// 		return search(root->left, key);
// 	}

// 	return search(root->right, key);
// }


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

class LL {
public:
	node* head;
	node* tail;
};

LL flattenTree(node* root) {
	LL p;
	if (root == NULL) {
		p.head = p.tail = NULL;
		return p;
	}
	if (root->right == NULL and root->left == NULL) {
		p.head = root;
		p.tail = root;
		return p;
	}
	else if (root->right == NULL and root->left != NULL) {
		LL leftLL = flattenTree(root->left);
		leftLL.tail->right = root;
		p.head = leftLL.head;
		p.tail = root;
		return p;
	}
	else if (root->left == NULL and root->right != NULL) {
		LL rightLL = flattenTree(root->left);
		root->right = rightLL.head;
		p.head = root;
		p.tail = rightLL.tail;
		return p;
	}
	LL l = flattenTree(root->left);
	LL r = flattenTree(root->right);
	l.tail->right = root;
	root->right = r.head;
	p.head = l.head;
	p.tail = r.tail;
	return p;
}


//input : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1

int main() {
	node* root = NULL;
	root = insertBST(root, 4);
	root = insertBST(root, 2);
	root = insertBST(root, 1);
	root = insertBST(root, 3);
	root = insertBST(root, 6);
	root = insertBST(root, 5);
	root = insertBST(root, 7);
	levelOrder(root);
	cout << endl;
	LL temp = flattenTree(root);
	node* x = temp.head;
	while (x != NULL) {
		cout << x->data << " ";
		x = x->right;
	}

	return 0;
}

