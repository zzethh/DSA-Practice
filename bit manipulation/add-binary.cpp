class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = 0;
        string ans = "";
        while (i < a.length() or i < b.length() or carry != 0) {
            int x = 0;
            if (i < a.length() and a[a.length() - i - 1] == '1') x = 1;
            int y = 0;
            if (i < b.length() and b[b.length() - i - 1] == '1') y = 1;
            ans = to_string((x + y + carry) % 2) + ans;
            carry = (x + y + carry) / 2;
            i++;
        }

        return ans;
    }
};