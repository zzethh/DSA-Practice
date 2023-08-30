class Solution {
public:
    unordered_set<string> se;
    unordered_map<string, bool> dp;
    bool helper(string s) {
        if (s.length() == 0) {
            return true;
        }
        if (dp.find(s) != dp.end()) return dp[s];
        for (int i = 0; i < s.length(); i++) {
            bool subprob = false;
            if (se.find(s.substr(0, i + 1)) != se.end()) {
                subprob = helper(s.substr(i + 1));
            }
            if (subprob) return dp[s] = true;
        }
        return dp[s] = false;
    }
    bool wordBreak(string s, vector<string>& d) {
        for (auto x : d) {
            se.insert(x);
        }
        //vector<bool> dp(s.length()+1,-1);
        return helper(s);
    }
};