#include<bits/stdc++.h>
using namespace std;


void merge(vector<int> &arr, int s, int e) {
	int i = s;
	int mid = (s + e) / 2;
	int j = mid + 1;
	vector<int> v;
	while (i <= mid and j <= e) {
		if (arr[i] < arr[j]) {
			v.push_back(arr[i]);
			i++;
		}
		else {
			v.push_back(arr[j]);
			j++;
		}
	}
	while (i <= mid) {
		v.push_back(arr[i]);
		i++;
	}
	while (j <= e) {
		v.push_back(arr[j]);
		j++;
	}
	int k = 0;
	for (int idx = s; idx <= e; idx++) {
		arr[idx] = v[k++];
	}
}

void mergeSort(vector<int> &v, int s, int e) {
	if (s >= e) {
		return;
	}
	int mid = (s + e) / 2;
	mergeSort(v, s, mid);
	mergeSort(v, mid + 1, e);
	return merge(v, s, e);
}


int main() {
	vector<int> v{10, 5, 2, 0, 7, 6, 9};
	//int v[20] = {10, 5, 2, 0, 7, 6, 4};
	int s = 0;
	int e = v.size() - 1;
	mergeSort(v, s, e);
	for (int x : v) {
		cout << x << " ";
	}
	return 0;
}

