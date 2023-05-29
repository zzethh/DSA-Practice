class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_map<char, bool> m2;
        if (s.length() != t.length()) return false;

        for (int i = 0; i < s.length(); i++) {
            if (m2[t[i]]) {
                if (m[s[i]] == t[i]) {
                    continue;
                }
                else return false;
            }
            else {
                if (m.find(s[i]) != m.end()) {
                    return false;
                }
                else {
                    m[s[i]] = t[i];
                    m2[t[i]] = true;
                }
            }
        }
        return true;
    }
};