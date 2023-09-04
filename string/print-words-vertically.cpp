class Solution {
public:
    vector<string> printVertically(string s) {
        stringstream ss(s);
        vector<string> tokens;
        string token;
        int maxi = 0;
        while (getline(ss, token, ' ')) {
            maxi = max(maxi, (int)token.length());
            tokens.push_back(token);
        }
        vector<string> v;
        for (int i = 0; i < maxi; i++) {
            string x = "";
            for (int j = 0; j < tokens.size(); j++) {
                if (i >= tokens[j].size()) {
                    x += " ";
                    continue;
                }
                x += tokens[j][i];
            }
            int idx = x.length() - 1;
            while (idx >= 0 and x[idx] == ' ') {
                x.pop_back();
                idx--;
            }
            v.push_back(x);
        }
        return v;
    }
};