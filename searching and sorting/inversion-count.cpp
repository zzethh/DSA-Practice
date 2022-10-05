#include<bits/stdc++.h>
using namespace std;


int merge(vector<int> &arr, int s, int e) {
	int i = s;
	int mid = (s + e) / 2;
	int j = mid + 1;
	vector<int> v;
	long long int cnt = 0;
	while (i <= mid && j <= e) {
		if (arr[i] < arr[j]) {
			v.push_back(arr[i]);
			i++;
		}
		else {
			cnt = cnt + (mid - i + 1);
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
	return cnt;
}

long long int inversion(vector<int> &arr, int s, int e) {
	if (s >= e) {
		return 0;
	}
	int m = (s + e) / 2;
	int C1 = inversion(arr, s, m);
	int C2 = inversion(arr, m + 1, e);
	int CI = merge(arr, s, e);
	return C1 + C2 + CI;
}


int main() {
	vector<int> v{0, 5, 2, 3, 1};
	int s = 0;
	int e = v.size() - 1;
	cout << inversion(v, s, e);
	return 0;
}

