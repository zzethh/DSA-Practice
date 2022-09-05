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

int search2(int arr[], int l, int ptr, int target) {
	if (ptr == l) {
		return -1;
	}
	if (arr[ptr] == target) {
		return ptr;
	}
	return search2(arr, l, ptr + 1, target);
}

void search3(int arr[], int l, int ptr, int target, vector<int> &output) {
	if (ptr == l) {
		return;
	}
	if (arr[ptr] == target) {
		output.push_back(ptr);
	}
	search3(arr, l, ptr + 1, target, output);
}


int main() {
	int arr[] = {10, 6, 7, 8, 9, 10, 10};
	int l = sizeof(arr) / sizeof(int);
	vector<int> output;
	int ptr = 0;
	int target;
	cin >> target;
	search3(arr, l, ptr, target, output);
	for (int x : output) {
		cout << x << " ";
	}
	return 0;
}