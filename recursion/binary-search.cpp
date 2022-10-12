#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> v, int s, int e, int k) {
	if (s > e) {
		return -1;
	}
	int mid = (s + e) / 2;

	if (v[mid] == k) return mid;

	if (v[mid] < k) {
		return binarySearch(v, mid + 1, e, k);
	}
	else return binarySearch(v, s, mid - 1, k);
}

int main() {
	vector<int> v = {1, 2, 3, 4, 5, 6};
	int s = 0;
	int e = v.size() - 1;
	cout << binarySearch(v, s, e, 4);

	return 0;
}

