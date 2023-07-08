class Solution {
public:
	vector <int> bottomView(Node *root) {
		map<int, int> m;
		queue<pair<Node*, int>> q;
		//int d=0;
		q.push({root, 0});
		while (!q.empty()) {
			auto f = q.front();
			m[f.second] = f.first->data;
			q.pop();
			if (f.first->left != NULL) {
				q.push({f.first->left, f.second - 1});
			}
			if (f.first->right != NULL) {
				q.push({f.first->right, f.second + 1});
			}
		}
		vector<int> ans;
		for (auto x : m) {
			ans.push_back(x.second);
		}
		return ans;
	}
};