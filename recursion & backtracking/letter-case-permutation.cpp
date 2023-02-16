class Solution {
public:
    vector<string> ans;
    void helper(string s, int i, string temp) {
        if (i == s.length()) {
            ans.push_back(temp);
            return;
        }
        if (isdigit(s[i])) {
            helper(s, i + 1, temp + s[i]);
            return;
        }
        helper(s, i + 1, temp + (char)tolower(s[i]));
        helper(s, i + 1, temp + (char)toupper(s[i]));
    }
    vector<string> letterCasePermutation(string s) {
        string temp = "";
        helper(s, 0, temp);
        return ans;
    }
};