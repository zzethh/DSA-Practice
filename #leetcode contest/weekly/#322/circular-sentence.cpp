class Solution {
public:
    bool isCircularSentence(string s) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, ' ')) {
            tokens.push_back(token);
            //  cout<<token<<endl;
        }

        for (int i = 1; i <= tokens.size(); i++) {
            int n = tokens[i - 1].length() - 1;
            if (tokens[i - 1][n] != tokens[i % (tokens.size())][0]) {
                return false;
            }
        }
        return true;
    }
};