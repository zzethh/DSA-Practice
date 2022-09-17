#include<bits/stdc++.h>
using namespace std;

int count_triplets(vector<int> v, int r) {
	unordered_map<int, int> left;
	unordered_map<int, int> right;
	for (auto x : v) {
		right[x]++;
		left[x] = 0;
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		right[v[i]]--;
		if (left[v[i] / r] and right[v[i]*r]) {
			int x = left[v[i] / r];
			int y = right[v[i] * r];
			sum = sum + x * y;
		}
		left[v[i]]++;
	}
	return sum;
}

int main() {

	vector<int> v = {1, 16, 4, 16, 64, 16};
	cout << count_triplets(v, 4);
	return 0;
}

