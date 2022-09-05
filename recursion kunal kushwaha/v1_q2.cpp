#include<bits/stdc++.h>
using namespace std;

int recursion(int arr[], int s, int e, int target) {
	int m = (s + e) / 2;
	if (s > m) {
		return -1;
	}

	if (arr[m] == target) {
		return m;
	}
	if (arr[m] > target) {
		return recursion(arr, s, m - 1, target);
	}
	return recursion(arr, m + 1, e, target);
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int target;
	cin >> target;
	cout << recursion(arr, 1, sizeof(arr) / sizeof(int), target);
	return 0;
}