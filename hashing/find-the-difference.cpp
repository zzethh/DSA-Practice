class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> m(26, 0);
        for (char c : s) {
            m[c - 'a']++;
        }
        for (char c : t) {
            if (m[c - 'a']) {
                m[c - 'a']--;
            }
            else {
                return c;
            }
        }
        return 'x';
    }
};