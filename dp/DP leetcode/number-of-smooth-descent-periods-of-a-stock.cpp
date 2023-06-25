class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] - prices[i] == 1) dp[i] = dp[i - 1] + 1;
            //else dp[i]=0;
        }
        long long sum = 0;
        for (auto x : dp) {
            sum += x;
        }
        return sum;
    }
};