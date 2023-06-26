class Solution {
public:
    int mod = 1e9 + 7;
    int helper(int low, int high, int zero, int one, int cnt, string s, vector<int> &dp) {
        if (cnt > high) return 0;
        if (dp[cnt] != -1) return dp[cnt];
        if (cnt >= low and cnt <= high) {
            // cout<<s<<endl;
            return dp[cnt] = (1 + helper(low, high, zero, one, cnt + zero, s, dp) + helper(low, high, zero, one, cnt + one, s, dp)) % mod;
        }
        // for(int i=0;i<zero;i++){
        //     s+='0';
        // }
        int z = helper(low, high, zero, one, cnt + zero, s, dp);
        // for(int i=0;i<zero;i++){
        //     s.pop_back();
        // }
        // for(int i=0;i<one;i++){
        //     s+='1';
        // }
        int o = helper(low, high, zero, one, cnt + one, s, dp);
        // for(int i=0;i<one;i++){
        //     s.pop_back();
        // }
        return dp[cnt] = (o + z) % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        string s = "";
        vector<int> dp(high + max(one, zero) + 1, -1);
        return helper(low, high, zero, one, 0, s, dp);
    }
};