#include<bits/stdc++.h>
using namespace std;

pair<int, int> findPair(vector<int> v, int k) {
	unordered_set<int> s;
	pair<int, int> p;
	for (auto x : v) {
		if (s.find(k - x) != s.end()) {
			return {x, k - x};
		}
		s.insert(x);
	}

	return { -1, -1};
}

int main() {
	vector<int> arr = {10, 5, 2, 3, -6, 9, 11};
	pair<int, int> p = findPair(arr, 4);
	cout << p.first << " " << p.second;
	return 0;
}

