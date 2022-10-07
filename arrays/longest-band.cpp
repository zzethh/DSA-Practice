#include<bits/stdc++.h>
using namespace std;

int longestBand(vector<int> arr) {
	int n = arr.size();
	unordered_set<int> s;
	for (int x : arr) {
		s.insert(x);
	}

	int maxi = INT_MIN;

	for (auto x : arr) {
		if (s.find(x - 1) == s.end()) {
			int cnt = 0;
			int temp = x;
			while (s.find(temp) != s.end()) {
				cnt++;
				temp = temp + 1;
			}
			maxi = max(maxi, cnt);
		}
		else continue;
	}

	return maxi;
}

int main() {
	vector<int> arr = {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
	cout << longestBand(arr);
	return 0;
}

