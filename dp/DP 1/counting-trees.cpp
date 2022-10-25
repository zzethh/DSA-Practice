#include<bits/stdc++.h>
using namespace std;


int count(int n) {
	if (n == 0 or n == 1) return 1;
	int ans = 0;
	for (int j = 1; j <= n; j++) {
		ans += count(j - 1) * count(n - j);
	}
	return ans;
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

int bottomUp(int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = 0;
		for (int j = 1; j <= i; j++) {
			dp[i] = dp[i] + dp[i - j] * dp[j - 1];
		}
	}
	return dp[n];
}

int main() {
	int dp[100] = {0};
	//vector<int> arr = {50, 4, 10, 8, 30, 100};
	cout << count(3);
	cout << bottomUp(3);
	return 0;
}