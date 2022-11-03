class node {
public:
	int data;
	node* left;
	node* right;
	node(int value) {
		data = value;
		left = NULL;
		right = NULL;
	}
};

class cmp {
public:
	bool operator()(node* a, node* b) {
		return a->data > b->data;
	}
};

class Solution
{
public:
	void traverse(node* root, string s, vector<string> &v) {
		if (root == NULL) {
			return;
		}
		if (root->left == NULL and root->right == NULL) {
			v.push_back(s);
			return;
		}
		traverse(root->left, s + '0', v);
		traverse(root->right, s + '1', v);
	}
	vector<string> huffmanCodes(string S, vector<int> f, int N)
	{
		priority_queue<node*, vector<node*>, cmp> pq;

		for (int i = 0; i < N; i++) {
			node* temp = new node(f[i]);
			pq.push(temp);
		}
		while (pq.size() > 1) {
			node* a = pq.top();
			pq.pop();

			node* b = pq.top();
			pq.pop();

			int sum = a->data + b->data;
			node* n = new node(sum);
			n->left = a;
			n->right = b;
			pq.push(n);
		}
		vector<string> v;
		traverse(pq.top(), "", v);
		return v;
	}
};