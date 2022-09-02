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

node* levelOrderBuild(vector<int> v) {
	queue<node*> q;
	node* x = new node(v[0]);
	int i = 0;
	q.push(x);
	while (!q.empty() && i < v.size()) {
		node* front = q.front();
		q.pop();
		node* nleft = new node(v[2 * i + 1]);
		node* nright = new node(v[2 * i + 2]);
		if (nleft->data == -1) {
			front->left = NULL;
		} else {
			front->left = nleft;
			q.push(nleft);
		}

		if (nright->data == -1) {
			front->right = NULL;
		} else {
			front->right = nright;
			q.push(nright);
		}
		i++;
	}
	return x;
}




int main() {
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);

	vector<int> v = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, -1, -1, -1, -1, -1};
	node* root1 = levelOrderBuild2(v);
	levelOrder(root1);


	return 0;
}

