#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findtriplets(vector<int> arr, int target) {
	vector<vector<int>> v;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size() - 2; i++) {
		int j = i + 1;
		int k = arr.size() - 1;
		while (j < k) {
			int sum = arr[i] + arr[j] + arr[k];
			if (sum == target) {
				v.push_back({arr[i], arr[j], arr[k]});
				j++;
				k--;
			}
			else if (sum < target) {
				j++;
			}
			else k--;
		}
	}

	return v;
}

int main() {
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
	vector<vector<int>> v = findtriplets(arr, 18);
	for (auto x : v) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	return 0;
}

