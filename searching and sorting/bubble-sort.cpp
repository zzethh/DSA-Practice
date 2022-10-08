#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &v) {
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = 0; j < v.size() - 1 - i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
			}
		}
	}
}

int main() {
	vector<int> arr = {5, 4, 3, 2, 1};
	selectionSort(arr);
	for (auto x : arr) {
		cout << x << " ";
	}
	return 0;
}

