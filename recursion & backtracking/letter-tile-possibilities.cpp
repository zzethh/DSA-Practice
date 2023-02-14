class Solution {
public:
    unordered_set<string> result;
    void helper(string s, unordered_map<int, int> m, string ans, int i) {
        if (i == s.length()) {
            return;
        }
        for (int k = 0; k < s.length(); k++) {
            if (m[k] == 0) {
                ans += s[k];
                m[k]++;
                result.insert(ans);
                helper(s, m, ans, i + 1);
                ans.pop_back();
                m[k]--;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        string ans = "";
        unordered_map<int, int> m;
        helper(tiles, m, ans, 0);
        return result.size();
    }
};