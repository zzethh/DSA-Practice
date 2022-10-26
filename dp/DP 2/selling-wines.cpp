#include<bits/stdc++.h>
using namespace std;

// int profit(vector<int> v) {

// }

int topDown(vector<int> v, int l, int r, int dp[][10], int y) {
	if (l > r) {
		return 0;
	}

	if (dp[l][r]) return dp[l][r];

	int pick_left = y * v[l] + topDown(v, l + 1, r, dp, y + 1);
	int pick_right = y * v[r] + topDown(v, l, r - 1, dp, y + 1);
	return dp[l][r] = max(pick_right, pick_left);
}

int bottomUp(vector<int> v) {
	int n = v.size();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				dp[i][j] = n * v[i];
			}
			else if (i < j) {
				int y = n - (j - i);
				int pick_left = y * v[i] + dp[i + 1][j];
				int pick_right = y * v[j] + dp[i][j - 1];
				dp[i][j] = max(pick_right, pick_left);
			}
		}
	}

	return dp[0][n - 1];

}

int main() {
	vector<int> vine = {2, 3, 5, 1, 4};

	int dp[10][10] = {0};

	cout << topDown(vine, 0, 4, dp, 1);
	cout << bottomUp(vine);
	return 0;
}