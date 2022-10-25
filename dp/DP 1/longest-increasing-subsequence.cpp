#include<bits/stdc++.h>
using namespace std;


int LIS(vector<int> arr, int i, int prev) {
	if (i == arr.size()) {
		return 0;
	}

	int exc = LIS(arr, i + 1, prev);
	int inc = INT_MIN;
	if (prev == -1 or arr[i] > arr[prev]) {
		inc = 1 + LIS(arr, i + 1, i);
	}

	return max(inc, exc);

}

// int topDown(vector<int> arr, int i, int dp[]) {
// 	if (i == arr.size() - 1) {
// 		return 0;
// 	}
// 	if (i >= arr.size()) {
// 		return INT_MAX;
// 	}
// 	if (dp[i]) return dp[i];
// 	int ans = INT_MAX;
// 	for (int jump = 1; jump <= arr[i]; jump++) {
// 		ans = min(ans, minJumsps(arr, i + jump));
// 	}

// 	return dp[i] = ans + 1;
// }

int bottomUp(vector<int> arr) {
	int n = arr.size();
	vector<int> dp(n + 1, 0);
	for (int i = 0; i < arr.size(); i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}

	int ans = INT_MIN;
	for (int i = 0; i < arr.size(); i++) {
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main() {
	int dp[100] = {0};
	vector<int> arr = {50, 4, 10, 8, 30, 100};
	cout << bottomUp(arr);
	cout << LIS(arr, 0, -1);
	return 0;
}