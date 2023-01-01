#include<bits/stdc++.h>
using namespace std;

int minJumsps(vector<int> arr, int i) {
	if (i == arr.size() - 1) {
		return 0;
	}
	if (i >= arr.size()) {
		return INT_MAX;
	}
	int ans = INT_MAX;
	for (int jump = 1; jump <= arr[i]; jump++) {
		ans = min(ans, minJumsps(arr, i + jump));
	}

	return ans + 1;
}

int topDown(vector<int> arr, int i, int dp[]) {
	if (i == arr.size() - 1) {
		return 0;
	}
	if (i >= arr.size()) {
		return INT_MAX;
	}
	if (dp[i]) return dp[i];
	int ans = INT_MAX;
	for (int jump = 1; jump <= arr[i]; jump++) {
		ans = min(ans, minJumsps(arr, i + jump));
	}

	return dp[i] = ans + 1;
}

// int bottomUp(vector<int> arr) {
// 	int n = arr.size();
// 	vector<int> dp(n + 1, 0);
// 	dp[n-1] = 0;
// 	for (int i = 1; i <= n - 1; i++) {
// 		dp[i] = INT_MAX;
// 		for (int j = 1; j <= arr[i]; j++) {
// 			if (i - j >= 0 and arr[i - j] != INT_MAX) {
// 				dp[i] = min(dp[i], dp[i - j]);
// 			}
// 		}
// 	}
// 	return dp[n - 1];
// }

int main() {
	int dp[100] = {0};
	vector<int> arr = {3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 2, 5};
	cout << minJumsps(arr, 0);
	cout << topDown(arr, 0, dp);
	return 0;
}