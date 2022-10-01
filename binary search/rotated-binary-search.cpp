#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> v, int k) {
	int s = 0;
	int e = v.size() - 1;
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (v[mid] == k) {
			ans = mid;
		}
		if (v[s] <= v[mid]) {
			if (k >= v[s] and k <= v[mid]) {
				e = mid - 1;
			}
			else s = mid + 1;
		}
		else if (v[mid] <= v[e]) {
			if (k <= v[e] and k >= v[mid]) {
				s = mid + 1;
			}
			else e = mid - 1;;
		}
	}
	return ans;
}


int main() {
	vector<int> v{7, 9, 10, 1, 2, 3, 4, 5, 6};
	int target = 2;
	cout << lowerBound(v, target);
	return 0;
}

