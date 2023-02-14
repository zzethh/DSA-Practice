class Solution {
public:
    vector<string> v;
    void helper(int n, int open, int close, string ans) {
        if (open == n and close == n) {
            v.push_back(ans);
        }
        if (open < n) {
            helper(n, open + 1, close, ans + '(');
        }
        if (close < open) {
            helper(n, open, close + 1, ans + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        string ans = "";
        helper(n, 0, 0, ans);
        return v;
    }
};