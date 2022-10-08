#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &v) {
	for (int i = 0; i < v.size() - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[j] < v[min_index]) {
				min_index = j;
			}
		}
		swap(v[i], v[min_index]);
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

