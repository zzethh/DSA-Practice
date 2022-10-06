#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int s, int e) {
	int pivot = a[e];
	int i = s - 1;
	for (int j = s; j < e; j++) {
		if (a[j] < pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[e]);
	return i + 1;
}


int QuickSort(vector<int> &a, int s, int e, int k) {
	// if (s >= e) {
	// 	return -1;
	// }
	int p = partition(a, s, e);
	if (p == k) {
		return a[p];
	}
	else if (k < p) {
		return QuickSort(a, s, p - 1, k);
	}
	else return QuickSort(a, p + 1, e, k);
}


int main() {
	vector<int> v{0, 5, 2, 3, 1};
	int s = 0;
	int e = v.size() - 1;
	cout << QuickSort(v, s, e, 4);
	// for (auto x : v) {
	// 	cout << x << " ";
	// }
	return 0;
}

