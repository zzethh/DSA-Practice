#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

bool canPlace(vector<int> a , vector<int> b) {
	if (a[0] < b[0] and a[1] < b[1]  and a[2] < b[2]) {
		return true;
	}
	return false;
}
int box(vector<vector<int>> v) {
	sort(v.begin(), v.end(), compare);
	int n = v.size();
	vector<int> dp(n + 1, 0);
	for (int i = 0; i < n; i++) {
		dp[i] = v[i][2];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (canPlace(v[j], v[i])) {
				int current_height = v[i][2];
				if (dp[j] + current_height > dp[i]) {
					dp[i] = dp[j] + current_height;
				}
			}
		}
	}

	int ans = INT_MIN;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
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

// int bottomUp(int n) {
// 	vector<int> dp(n + 1, 0);
// 	dp[0] = 1;
// 	dp[1] = 1;
// 	for (int i = 2; i <= n; i++) {
// 		dp[i] = 0;
// 		for (int j = 1; j <= i; j++) {
// 			dp[i] = dp[i] + dp[i - j] * dp[j - 1];
// 		}
// 	}
// 	return dp[n];
// }

int main() {
	int dp[100] = {0};
	vector<vector<int>> boxes = {
		{2, 1, 2},
		{3, 2, 3},
		{2, 2, 8},
		{2, 3, 4},
		{2, 2, 1},
		{4, 4, 5}
	};
	cout << box(boxes);
	return 0;
}