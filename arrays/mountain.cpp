#include<bits/stdc++.h>
using namespace std;

bool isPeak(vector<int> v, int i) {
	return v[i] > v[i - 1] and v[i] > v[i + 1];
}

int findwidth(vector<int> v) {
	int maxi = INT_MIN;
	for (int i = 1; i < v.size() - 1; i++) {
		if (isPeak(v, i)) {
			int cnt1 = 1;
			int j = i;
			while (j >= 1 and v[j] > v[j - 1]) {
				j--;
				cnt1++;
			}
			int k = i;
			while (k <= v.size() - 2 and v[k] > v[k + 1]) {
				k++;
				cnt1++;
			}

			maxi = max(maxi, cnt1);
		}
	}
	return maxi;
}

int main() {
	vector<int> arr = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
	cout << findwidth(arr);
	return 0;
}

