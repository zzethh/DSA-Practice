class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> m;
        for (auto x : s) {
            m[x]++;
        }
        vector<char> t(s.length());
        set<pair<int, char>, greater<pair<int, char>>> st;
        for (auto x : m) {
            st.insert({x.second, x.first});
        }
        int i = 0;
        auto x = *(st.begin());
        int freq = x.first;
        char ch = x.second;
        while (!st.empty()) {
            if (freq == 0) {
                st.erase(st.begin());
                x = *(st.begin());
                freq = x.first;
                ch = x.second;
            }
            if (freq > (s.length() + 1) / 2) return "";
            for (i; i<s.length() and freq>0; i += 2) {
                t[i] = ch;
                freq--;
            }
            for (auto x : t) {
                cout << x;
            }
            cout << endl;
            if (i >= s.length()) i = 1;
        }
        string ans = "";
        for (auto x : t) {
            ans += x;
        }
        return ans;
    }
};