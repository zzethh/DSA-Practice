class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        int i = 0, j = 0;
        while (i < n and j < n) {
            dp[i][j] = 1;
            if (j < n - 1 and s[i] == s[j + 1]) dp[i][j + 1] = 1;
            i++;
            j++;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (j - i >= 2) {
                    if (s[i] == s[j] and dp[i + 1][j - 1]) {
                        dp[i][j] = 1;
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //cout<<dp[i][j]<<" ";
                if (dp[i][j]) cnt++;
            }
            //cout<<endl;
        }

        return cnt;
    }
};