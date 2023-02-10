class Solution {
public:
    bool helper(string st) {
        unordered_set<int> a;
        unordered_set<int> b;
        for (char x : st) {
            if (isupper(x) == false) {
                int temp = x - 'a';
                a.insert(temp);
            }
            else {
                int temp = x - 'A';
                b.insert(temp);
            }
        }

        for (auto x : st) {
            if (isupper(x)) {
                auto f = a.find(x - 'A');
                if (f == a.end()) {
                    return false;
                }
            }
            else {
                auto f = b.find(x - 'a');
                if (f == b.end()) {
                    return false;
                }
            }
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        string ans;
        int mini = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j <= s.length() - i; j++) {
                string x = s.substr(i, j);
                ///cout<<x<<" ";
                if (helper(x)) {
                    if (x.length() > mini) {
                        ans = x;
                        mini = x.length();
                    }
                }
            }
        }
        return ans;
    }
};