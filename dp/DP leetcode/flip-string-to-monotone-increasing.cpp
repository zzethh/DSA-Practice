class Solution {
public:
    int helper(string &s, int i, bool mono, vector<vector<int>> &dp) {
        if (i == s.length()) {
            return 0;
        }
        if (dp[i][mono] != -1) return dp[i][mono];

        if (mono and s[i] == '0') {
            return dp[i][mono] = min(helper(s, i + 1, true, dp), 1 + helper(s, i + 1, false, dp));
        }
        if (mono and s[i] == '1') {
            return dp[i][mono] = min(helper(s, i + 1, false, dp), 1 + helper(s, i + 1, true, dp));
        }
        if (!mono and s[i] == '1') {
            return dp[i][mono] = helper(s, i + 1, false, dp);
        }
        //if(!mono and s[i]=='0'){
        return dp[i][mono] = 1 + helper(s, i + 1, false, dp);
        //}
    }
    int minFlipsMonoIncr(string s) {
        // int count1=0;
        // int flip=0;
        // for(int i=0;i<s.length();i++){
        //     if(s[i]=='1'){
        //         count1++;
        //     }
        //     if(s[i]=='0'){
        //         if(count1){
        //             flip++;
        //         }
        //     }
        //     if(count1<flip){
        //         flip=count1;
        //     }
        // }

        // return flip;
        vector<vector<int>> dp(s.length() + 1, vector<int>(2, -1));
        return helper(s, 0, true, dp);
    }
};