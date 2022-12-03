#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &v) {
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = 0; j <= v.size() - 1 - i; j++) {
			swap(v[j], v[j + 1]);
		}
	}
}

void insertion_sort(vector<int> &v) {

}

void selection_sort(vector<int> &v) {

}

int main() {
	vector<int> v = {5, 4, 3, 2, 1};
	for (auto x : v) {
		cout << x << " ";
	}
	return 0;
}

