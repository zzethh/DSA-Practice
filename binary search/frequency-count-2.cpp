#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> v, int k) {
	int s = 0;
	int e = v.size();
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (v[mid] == k) {
			ans = mid;
			s = mid + 1;
		}
		else if (v[mid] > k) {
			e = mid - 1;
		}
		else s = mid + 1;
	}
	return ans;
}


int main() {
	vector<int> v{0, 1, 1, 2, 2, 2, 2, 3, 4, 4, 5, 10};
	int target = 2;
	cout << lowerBound(v, target);
	return 0;
}

