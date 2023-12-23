class Solution {
public:
    string reverseWords(string s) {
        string token;
        stringstream ss(s);
        vector<string> tokens;
        while (getline(ss, token, ' ')) {
            tokens.push_back(token);
        }
        string t = "";
        for (auto x : tokens) {
            reverse(x.begin(), x.end());
            t += x;
            t = t + " ";
        }
        t.pop_back();
        return t;
    }
};