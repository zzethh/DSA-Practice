#include<bits/stdc++.h>
using namespace std;

int rotatedSearch(vector<int> arr, int s, int e, int target) {
	int m = (s + e) / 2;
	if (s > e) {
		return -1;
	}
	if (arr[m] == target) {
		return m;
	}
	if (arr[s] <= arr[m]) {
		if (target >= arr[s] && target <= arr[m]) {
			return rotatedSearch(arr, s, m - 1, target);
		} else {
			return rotatedSearch(arr, m + 1, e, target);
		}
	}
	if (arr[m] < arr[e]) {
		if (target >= arr[m] && target <= arr[e]) {
			return rotatedSearch(arr, m + 1, e, target);
		} else {
			return rotatedSearch(arr, s, m - 1, target);
		}
	}
}

int main() {
	vector<int> v = {5, 6, 7, 8, 9, 1, 2, 3};
	int s = 0;
	int e = v.size() - 1;
	cout << rotatedSearch(v, s, e, 8);

	return 0;
}

