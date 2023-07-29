class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> v;
        for (auto x : words) {
            string s = "";
            for (int i = 0; i < x.length(); i++) {
                auto y = x[i];
                if (y == separator) {
                    if (!s.empty()) v.push_back(s);
                    s = "";
                    continue;
                }
                if (i == x.length() - 1) {
                    s += y;
                    if (!s.empty()) v.push_back(s);
                }
                s += y;
            }
        }
        return v;
    }
};