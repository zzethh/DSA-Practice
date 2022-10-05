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


void QuickSort(vector<int> &a, int s, int e) {
	if (s >= e) {
		return;
	}
	int p = partition(a, s, e);
	QuickSort(a, s, p - 1);
	QuickSort(a, p + 1, e);
}


int main() {
	vector<int> v{0, 5, 2, 3, 1};
	int s = 0;
	int e = v.size() - 1;
	QuickSort(v, s, e);
	for (auto x : v) {
		cout << x << " ";
	}
	return 0;
}

