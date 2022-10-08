#include<bits/stdc++.h>
using namespace std;

int trapwater(vector<int> v) {
	int n = v.size();
	if (n <= 2) return 0;

	vector<int> left(n, 0), right(n, 0);
	left[0] = v[0];
	right[n - 1] = v[n - 1];

	for (int i = 1; i < n; i++) {
		left[i] = max(v[i], left[i - 1]);
		right[n - i - 1] = max(right[n - i], v[n - i - 1]);
	}

	int area = 0;
	for (int i = 0; i < v.size(); i++) {
		area = area + min(right[i], left[i]) - v[i];
	}
	return area;

}

int main() {
	vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout << trapwater(arr);
	return 0;
}

