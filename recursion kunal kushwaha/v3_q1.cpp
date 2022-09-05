#include<bits/stdc++.h>
using namespace std;

bool sort(int arr[], int l, int ptr) {
	if (ptr == l - 1) {
		return true;
	}
	if (arr[ptr] < arr[ptr + 1]) {
		return sort(arr, l, ptr + 1);
	}
	return false;
}

int main() {
	int arr[] = {6, 7, 8, 9, 1};
	int l = sizeof(arr) / sizeof(int);
	int ptr = 0;
	cout << sort(arr, l, ptr);
	return 0;
}