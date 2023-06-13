class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n);
        string a = to_string(2 * n);
        string b = to_string(3 * n);
        s = s + a + b;
        cout << s << endl;
        vector<int> v(10, 0);
        for (int i = 0; i < s.length(); i++) {
            int dig = s[i] - '0';
            v[dig]++;
        }
        if (v[0] != 0) return false;
        for (int i = 0; i <= 9; i++) {
            if (v[i] >= 2) return false;
        }
        return true;
    }
};