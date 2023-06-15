class Solution {
public:
    bool helper(string s) {
        set<char> st = {'a', 'e', 'i', 'o', 'u'};
        int n = s.length();
        if (st.find(s[0]) != st.end() and st.find(s[n - 1]) != st.end()) {
            return true;
        }
        return false;
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt = 0;
        for (int i = left; i <= right; i++) {
            if (words[i] == "") continue;
            if (helper(words[i])) {
                cnt++;
            }
        }
        return cnt;
    }
};