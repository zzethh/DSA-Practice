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


int main() {
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);



	return 0;
}

