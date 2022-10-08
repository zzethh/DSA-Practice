#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		int e = v[i];
		int j = i - 1;
		while (j >= 0 and v[j] > e) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = e;
	}
}

int main() {
	vector<int> arr = {5, 2, 9, 1, 100};
	insertionSort(arr);
	for (auto x : arr) {
		cout << x << " ";
	}
	return 0;
}

