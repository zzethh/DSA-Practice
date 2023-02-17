class CombinationIterator {
public:
    vector<string> v;
    int i = 0;
    void helper(string s, int l, int i, string ans) {
        if (i == s.length()) {
            if (ans.length() == l) {
                v.push_back(ans);
            }
            return;
        }
        helper(s, l, i + 1, ans + s[i]);
        helper(s, l, i + 1, ans);
    }
    CombinationIterator(string characters, int combinationLength) {
        string ans = "";
        helper(characters, combinationLength, 0, ans);
        sort(v.begin(), v.end());
    }

    string next() {
        if (i != v.size()) {
            string temp = v[i];
            i++;
            return temp;
        }
        return "";
    }

    bool hasNext() {
        if (i == v.size()) return false;
        return true;
    }
};