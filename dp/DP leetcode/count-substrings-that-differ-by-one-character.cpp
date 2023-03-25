class Solution {
public:
    int countSubstrings(string s, string t) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < t.size(); j++) {
                int x = i;
                int y = j;
                int d = 0;
                while (x < s.size() and y < t.size()) {
                    if (s[x] != t[y]) {
                        d++;
                    }
                    if (d == 1) cnt++;
                    if (d > 1) break;
                    x++;
                    y++;
                }
            }
        }
        return cnt;
    }
};