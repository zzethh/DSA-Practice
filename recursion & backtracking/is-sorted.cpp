#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> v, int i) {
	if (i >= v.size() - 1) {
		return true;
	}

	if (v[i] > v[i + 1]) {
		return false;
	}

	return isSorted(v, i + 1);
}

int main() {
	vector<int> v = {1, 2, 9, 3, 4, 5};
	cout << isSorted(v, 0);

	return 0;
}

