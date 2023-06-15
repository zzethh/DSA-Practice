class Solution {
public:
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxzy"};
    void helper(string input, string output, int i, vector<string> &ans) {
        if (input[i] == '\0') {
            if (!output.empty())ans.push_back(output);
            return;
        }
        int digit = input[i] - '0';
        for (int k = 0; k < v[digit].size(); k++) {
            helper(input, output + v[digit][k], i + 1, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string t = "";
        helper(digits, t, 0, ans);
        return ans;
    }
};