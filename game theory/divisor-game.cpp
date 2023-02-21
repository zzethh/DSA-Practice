class Solution {
public:
    bool helper(int n, bool x) {
        if (n == 1) return false;
        if (n == 2) return true;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                bool sub = helper(n - i, !x);
                if (!sub and x == 1) return true;
                if (sub) return true;
            }
        }
        /// if(x==0) return true;
        return false;
    }
    int dp[1001];
    bool helper2(int n) {
        if (n == 1) return false;
        if (dp[n] != -1) return dp[n];
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                if (helper2(n - i) == 0) return dp[n] = 1;
            }
        }
        return dp[n] = 0;
    }
    bool divisorGame(int n) {
        // helper(n);
        ///if(n%2==0) return true;
        memset(dp, -1, sizeof dp);
        return helper2(n);
    }
};