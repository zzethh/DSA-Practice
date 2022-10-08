#include<bits/stdc++.h>
using namespace std;

int minswaps(vector<int> v) {
	int n = v.size();
	int ans = 0;

	pair<int, int> ap[n];
	for (int i = 0; i < v.size(); i++) {
		ap[i].first = v[i];
		ap[i].second = i;
	}

	sort(ap, ap + n);

	vector<bool> visited(n, false);

	for (int i = 0; i < n; i++) {

		int old_position = ap[i].second;
		if (visited[i] == true or old_position == i) {
			continue;
		}

		int node = i;
		int cycle = 0;
		while (!visited[node]) {
			visited[node] = true;
			int nextnode = ap[node].second;
			node = nextnode;
			cycle++;
		}

		ans += cycle - 1;

	}

	return ans;
}

int main() {
	vector<int> arr = {10, 11, 5, 4, 3, 2, 1};
	cout << minswaps(arr);
	return 0;
}

