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

vector<int> search4(int arr[], int l, int ptr, int target, vector<int> &output) {
	if (ptr == l) {
		return output;
	}
	if (arr[ptr] == target) {
		output.push_back(ptr);
	}
	return search4(arr, l, ptr + 1, target, output);
}

vector<int> search5(int arr[], int l, int ptr, int target) {
	vector<int> output;
	if (ptr == l) {
		return output;
	}
	if (arr[ptr] == target) {
		output.push_back(ptr);
	}
	vector<int> v = search5(arr, l, ptr + 1, target);
	output.insert(end(output), begin(v), end(v));
	return output;
}

vector<int> search6(int arr[], int l, int ptr, int target) {
	vector<int> output;
	if (ptr == l) {
		return output;
	}
	vector<int> v = search6(arr, l, ptr + 1, target);
	if (arr[ptr] == target) {
		v.push_back(ptr);
	}
	return v;
}

int search7(int arr[], int s, int e, int target) {
	int m = (s + e) / 2;
	if (s > e) {
		return -1;
	}
	if (arr[m] == target) {
		return m;
	}
	if (arr[s] <= arr[m]) {
		if (target >= arr[s] && target <= arr[m]) {
			return search7(arr, s, m - 1, target);
		} else {
			return search7(arr, m + 1, e, target);
		}
	}
	if (arr[m] < arr[e]) {
		if (target >= arr[m] && target <= arr[e]) {
			return search7(arr, m + 1, e, target);
		} else {
			return search7(arr, s, m - 1, target);
		}
	}
}


int main() {
	int arr[] = {4, 5, 6, 7, 0, 1, 2, 3};
	int l = sizeof(arr) / sizeof(int);
	vector<int> output;
	int ptr = 0;
	int target;
	cin >> target;
	cout << search7(arr, 0, l - 1, target);
	return 0;
}