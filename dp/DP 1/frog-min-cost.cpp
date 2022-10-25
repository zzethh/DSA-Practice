#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int> arr, int i) {
	if (i == arr.size() - 1) {
		return 0;
	}

	if (i + 1 < arr.size() and i + 2 < arr.size()) return min(minCost(arr, i + 1) + abs(arr[i + 1] - arr[i]), minCost(arr, i + 2) + abs(arr[i + 2] - arr[i]));
	if (i + 1 < arr.size()) return minCost(arr, i + 1) + abs(arr[i + 1] - arr[i]);
	else return minCost(arr, i + 2) + abs(arr[i + 2] - arr[i]);

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
	dp[0] = 0;
	dp[1] = arr[1] - arr[0];
	for (int i = 2; i < arr.size(); i++) {
		dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]), dp[i - 2] + abs(arr[i] - arr[i - 2]));
	}
	return dp[n - 1];
}

int main() {
	int dp[100] = {0};
	vector<int> arr = {10, 30, 40, 20};
	cout << bottomUp(arr);
	cout << minCost(arr, 0);
	return 0;
}