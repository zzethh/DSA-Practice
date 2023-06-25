class Solution {
public:
    // string join(string a,string b){
    //    // int an=a.length()-1;
    //     return a+b.substr(1);
    // }
    int dp[1000][26][26];
    int helper(vector<string>& v, int start, int end, int i) {
        if (i == v.size()) return 0;
        if (dp[i][start][end] != -1) return dp[i][start][end];
        int first = v[i].size() - (end + 'a' == v[i][0]) + helper(v, start, v[i].back() - 'a', i + 1);
        int second = v[i].size() - (start + 'a' == v[i].back()) + helper(v, v[i][0] - 'a', end, i + 1);
        return dp[i][start][end] = min(first, second);
    }
    int minimizeConcatenatedLength(vector<string>& v) {
        memset(dp, -1, sizeof(dp));
        return v[0].size() + helper(v, v[0][0] - 'a', v[0].back() - 'a', 1);
    }
};