#include<bits/stdc++.h>
using namespace std;

int minCoins(vector<int> coins, int target) {
	if (target == 0) {
		return 0;
	}
	if (target < 0) {
		return INT_MAX;
	}
	int ans = INT_MAX;
	for (int i = 0; i < coins.size(); i++) {
		ans = min(ans, minCoins(coins, target - coins[i]));
	}
	return ans + 1;
}

int topDown(vector<int> coins, int target, int dp[]) {
	if (target == 0) {
		return 0;
	}
	if (target < 0) {
		return INT_MAX;
	}
	if (dp[target]) return dp[target];

	int ans = INT_MAX;
	for (int i = 0; i < coins.size(); i++) {
		ans = min(ans, topDown(coins, target - coins[i], dp));
	}
	return dp[target] = ans + 1;
}

int bottomUp(vector<int> coins, int target) {
	vector<int> dp(target + 1, 0);
	dp[0] = 0;
	for (int i = 1; i <= target; i++) {
		int ans = INT_MAX;
		for (int j = 0; j < coins.size(); j++) {
			if (i - coins[j] >= 0 and dp[i - coins[j]] != INT_MAX) {
				ans = min(ans, dp[target - coins[j]]);
			}
		}
		dp[i] = ans + 1;
	}
	return dp[target];
}

int main() {
	int dp[100] = {0};
	vector<int> coins = {1, 5, 7, 10};
	cout << minCoins(coins, 8);
	cout << topDown(coins, 8, dp);
	cout << bottomUp(coins, 8);
	return 0;
}