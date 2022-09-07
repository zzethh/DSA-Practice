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

int helper(node* root) {
	node* temp = root;
	while (temp and temp->left != NULL) {
		temp = temp->left;
	}
	return temp->data;
}

node* inOrderSuccessor(node* root, node* target) {
	if (target->right != NULL) {
		node* temp = target->right;
		while (temp->left != NULL) {
			temp = temp->left;
		}
		return temp;
	}

	node* temp = root;
	node* succ = NULL;
	while (temp != NULL) {
		if (temp->data > target->data) {
			succ = temp;
			temp = temp->left;
		} else if (temp->data < target->data) {
			temp = temp->right;
		}
		else {
			break;
		}
	}

	return succ;

}

//input : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1

int main() {
	node* root = NULL;
	root = insertBST(root, 8);
	root = insertBST(root, 3);
	root = insertBST(root, 10);
	root = insertBST(root, 1);
	root = insertBST(root, 6);
	root = insertBST(root, 14);
	root = insertBST(root, 4);
	root = insertBST(root, 7);
	root = insertBST(root, 13);
	levelOrder(root);
	cout << endl;

	node* t1 = root->left->right->right;
	cout << inOrderSuccessor(root, t1 )->data;

	return 0;
}

