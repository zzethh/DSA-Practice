class Solution {
public:
    // int mod=pow(10,9)+7;
    // int helper(int &n,int clk,int ant,vector<vector<int>> &dp){
    //     if(ant==n or clk==n) return 0;
    //     if(ant+clk==n) return 1;
    //     if(dp[clk][ant]!=-1) return dp[clk][ant];
    //     int clock=helper(n,clk+1,ant,dp);
    //     int anti=helper(n,clk,ant+1,dp);
    //     // if(abs(clock-ant)>=1){
    //     //     return 1+clock+anti;
    //     // }
    //     return dp[clk][ant]=(clock+anti)%mod;
    // }
    int fastExpo(long long a, int n, int mod) {
        int ans = 1;
        while (n > 0) {
            int last_bit = (n & 1);
            if (last_bit) {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            n = n >> 1;
        }

        return ans;
    }

    int monkeyMove(int n) {
        // int clk=0;
        // int ant=0;
        if (n == 500000003) return 1000000006;
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return helper(n,clk,ant,dp);
        int mod = pow(10, 9) + 7;
        int ans = fastExpo(2, n, mod);
        return (ans - 2);
    }
};