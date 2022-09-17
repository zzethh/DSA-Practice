#include<bits/stdc++.h>
using namespace std;


int count_triangle(vector<pair<int, int>> v) {
	unordered_map<int, int> x;
	unordered_map<int, int> y;
	for (int i = 0; i < v.size(); i++) {
		x[v[i].first]++;
		y[v[i].second]++;
	}
	int ans = 0;

	for (int i = 0; i < v.size() - 1; i++) {
		if (x[v[i].first] and x[v[i].second]) {
			ans = ans + (x[v[i].first] - 1) * (y[v[i].second] - 1);
		}
	}

	return ans;
}

int main() {
	vector<pair<int, int>> v = {{1, 2}, {2, 1}, {2, 2}, {2, 3}, {3, 2}};
	cout << count_triangle(v);
	return 0;
}

