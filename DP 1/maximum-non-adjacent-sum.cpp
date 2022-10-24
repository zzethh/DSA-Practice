#include<bits/stdc++.h>
using namespace std;

int maxsum = INT_MIN;
void maxSum(vector<int> arr, int sum, int i) {
	if (i > arr.size() - 1) {
		if (sum > maxsum) {
			maxsum = sum;
		}
		return;
	}
	maxSum(arr, sum + arr[i], i + 2);
	maxSum(arr, sum, i + 1);

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
	dp[0] = arr[0];
	dp[1] = max(arr[0], arr[1]);
	for (int i = 2; i < arr.size(); i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
	}
	return dp[n - 1];
}

int main() {
	int dp[100] = {0};
	vector<int> arr = {6, 10, 12, 7, 9, 14};
	cout << bottomUp(arr);
	maxSum(arr, 0, 0);
	cout << maxsum;
	return 0;
}