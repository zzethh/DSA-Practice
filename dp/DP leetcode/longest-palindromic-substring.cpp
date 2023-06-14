class Solution {
public:
    string longestPalindrome(string s) {
        //int maxi=INT_MIN;
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), 0));
        int i = 0;
        int j = 0;
        string ans;
        while (i < s.length() and j < s.length()) {
            if (s[i] == s[j]) {
                dp[i][j] = 1;
            }
            if (j < s.length() and s[i] == s[j + 1]) {
                dp[i][j + 1] = 1;
                ans = s.substr(i, 2);
            }
            i++;
            j++;
        }
        // for(int i=0;i<s.length();i++){
        //     for(int j=0;j<s.length();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int maxi = INT_MIN;
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = 0; j < s.length(); j++) {
                if (j > i + 1) {
                    //cout<<i<<" "<<j<<endl;
                    if (dp[i + 1][j - 1] == 1 and s[i] == s[j]) {
                        dp[i][j] = 1;
                        if (j - i + 1 > maxi) {
                            ans = s.substr(i, j - i + 1);
                            maxi = j - i + 1;
                        }
                    }
                }
            }
        }
        // cout<<endl;
        // for(int i=0;i<s.length();i++){
        //     for(int j=0;j<s.length();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        string temp = "";
        if (ans == "" and !s.empty()) return temp + s[0];
        return ans;
    }
};