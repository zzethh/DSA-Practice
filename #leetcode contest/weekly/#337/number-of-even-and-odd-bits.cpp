class Solution {
public:
    string tobinary(int n) {
        string s = "";
        while (n) {
            int rem = n % 2;
            if (rem == 0) s = '0' + s;
            else if (rem == 1) s = '1' + s;
            n = n / 2;
        }
        cout << s << endl;
        return s;
    }
    vector<int> evenOddBit(int n) {
        string s = tobinary(n);
        int odd = 0;
        int even = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                if ((s.length() - i - 1) % 2 == 0) {
                    even++;
                }
                else odd++;
            }
        }
        vector<int> ans;
        ans.push_back(even);
        ans.push_back(odd);
        return ans;
    }
};