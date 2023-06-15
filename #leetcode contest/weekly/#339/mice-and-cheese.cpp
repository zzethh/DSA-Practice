class Solution {
public:
//     int helper(vector<int>& r1,vector<int>& r2,int k,int i,int j,vector<vector<int>> &dp){
//         if((i==r1.size() or j==r2.size()) and k==0){
//             return 0;
//         }
//         if(i==r1.size() or j==r2.size()){
//             return INT_MIN;
//         }

//         int inc=INT_MIN;
//         if(dp[i][j]!=-1) return dp[i][j];

//         if(k>0) inc=r1[i]+helper(r1,r2,k-1,i+1,j+1,dp);
//         int exc=r2[j]+helper(r1,r2,k,i+1,j+1,dp);

//         return dp[i][j]=max(inc,exc);
//     }
//     int helper(vector<int>& r1,vector<int>& r2,int k,int i,vector<vector<int>> &dp){
//         if((i==r1.size()) and k==0){
//             return 0;
//         }
//         if(i==r1.size()){
//             return INT_MIN;
//         }

//         if(dp[i][k]!=-1) return dp[i][k];

//         int inc=INT_MIN;
//         if(k>0) inc=r1[i]+helper(r1,r2,k-1,i+1,dp);
//         int exc=r2[i]+helper(r1,r2,k,i+1,dp);

//         return dp[i][k]=max(inc,exc);
//     }

    int helper2(vector<int>& r1, vector<int>& r2, int k) {
        int n = r1.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= k; i++) dp[n][i] = INT_MIN;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= k; j++) {
                int inc = INT_MIN;
                if (j > 0) inc = r1[i] + dp[i + 1][j - 1];
                int exc = r2[i] + dp[i + 1][j];
                dp[i][k] = max(inc, exc);
            }
        }
        return dp[0][k];
    }
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        ///vector<vector<int>> dp(reward1.size()+1,vector<int>(k+1,-1));
        //return helper(reward1,reward2,k,0,dp);
        // return helper2(reward1,reward2,k);
        vector<vector<int>> ans;
        for (int i = 0; i < reward1.size(); i++) {
            ans.push_back({reward2[i] - reward1[i], reward1[i], reward2[i]});
        }
        sort(ans.begin(), ans.end());
        int score = 0;
        for (int i = 0; i < k; i++) {
            score += ans[i][1];
        }
        for (int i = k; i < reward1.size(); i++) {
            score += ans[i][2];
        }
        return score;
    }
};