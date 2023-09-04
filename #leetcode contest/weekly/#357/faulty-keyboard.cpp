class Solution {
public:
    string finalString(string s) {
        string t = "";
        for (auto x : s) {
            if (x == 'i') {
                reverse(t.begin(), t.end());
                continue;
            }
            t += x;
        }
        return t;
    }
};