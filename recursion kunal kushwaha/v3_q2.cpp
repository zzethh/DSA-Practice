#include<bits/stdc++.h>
using namespace std;

bool search(int arr[], int l, int ptr, int target) {
	if (ptr == l) {
		return false;
	}
	if (arr[ptr] == target) {
		return true;
	}
	return search(arr, l, ptr + 1, target);
}

int main() {
	int arr[] = {6, 7, 8, 9, 10};
	int l = sizeof(arr) / sizeof(int);
	int ptr = 0;
	int target;
	cin >> target;
	cout << search(arr, l, ptr, target);
	return 0;
}