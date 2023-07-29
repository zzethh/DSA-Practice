class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> v;
        for (int i = 0; i < words.size(); i++) {
            map<char, char> m;
            unordered_set<char> st;
            string s = "";
            for (int j = 0; j < words[i].length(); j++) {
                if (m.find(words[i][j]) != m.end()) {
                    s += m[words[i][j]];
                    continue;
                }
                if (st.find(pattern[j]) != st.end()) break;
                m[words[i][j]] = pattern[j];
                s += pattern[j];
                st.insert(pattern[j]);
            }
            if (s == pattern) {
                v.push_back(words[i]);
            }
        }
        return v;
    }
};