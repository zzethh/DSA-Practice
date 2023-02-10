class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char, int> m;
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            m[s[i]]++;
        }
        bool flag = false;
        for (auto x : m) {
            cout << x.first << "-" << x.second << " ";
            if (x.second >= 2) flag = true;
        }
        cout << endl;
        if (flag == false) ans++;
        for (int i = 3; i < s.length(); i++) {
            m[s[i]]++;
            m[s[i - 3]]--;
            bool flag2 = false;
            for (auto x : m) {
                cout << x.first << "-" << x.second << " ";
                if (x.second >= 2) flag2 = true;
            }
            cout << endl;
            if (flag2 == false) ans++;
        }
        return ans;
    }
};