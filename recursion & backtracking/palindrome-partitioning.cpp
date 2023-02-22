class Solution {
public:
    bool palin(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            else {
                i++;
                j--;
            }
        }
        return true;
    }
    vector<vector<string>> ans;
    void helper(string s, vector<string> temp) {
        if (s.length() == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < s.length(); i++) {
            string pref = s.substr(0, i + 1);
            string rest = s.substr(i + 1);
            if (palin(pref)) {
                temp.push_back(pref);
                helper(rest, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        helper(s, temp);
        return ans;
    }
};