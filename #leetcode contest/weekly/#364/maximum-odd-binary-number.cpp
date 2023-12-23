class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = 0;
        int cnt0 = 0;
        for (auto x : s) {
            if (x == '1') cnt++;
            else cnt0++;
        }
        string t = "";
        if (cnt) t += "1", cnt--;
        while (cnt0--) {
            t = '0' + t;
        }
        while (cnt--) {
            t = '1' + t;
        }
        return t;
    }
};