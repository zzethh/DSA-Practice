class Solution {
public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
		int m = mat.size();
		int n = mat[0].size();
		vector<vector<int>> pref(m, vector<int>(n));
		pref[0][0] = mat[0][0];
		for (int j = 1; j < mat[0].size(); j++) {
			pref[0][j] = pref[0][j - 1] + mat[0][j];
		}
		for (int i = 1; i < mat.size(); i++) {
			pref[i][0] = pref[i - 1][0] + mat[i][0];
			for (int j = 1; j < mat[0].size(); j++) {
				pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + mat[i][j];

			}
		}

		vector<vector<int>> ans(m, vector<int>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int ei = min(m - 1, i + k);
				int ej = min(n - 1, j + k);
				ans[i][j] = pref[ei][ej];
				if (i <= k) {
					if (j > k) ans[i][j] -= pref[ei][j - k - 1];
				}
				else {
					ans[i][j] -= pref[i - k - 1][ej];
					if (j > k) ans[i][j] -= pref[ei][j - k - 1] - pref[i - k - 1][j - k - 1];
				}
			}
		}
		return ans;
	}
};