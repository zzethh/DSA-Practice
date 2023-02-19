class Solution {
public:
    int minMaxDifference(int num) {
        string s1 = to_string(num);
        string s2 = to_string(num);
        int dig = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != '9') {
                dig = s1[i] - '0';
                /// cout<<i;
                break;
            }
        }

        int maxi = 0;
        for (auto x : s1) {
            int dig1 = x - '0';
            if (dig1 == dig) dig1 = 9;
            maxi = maxi * 10 + dig1;
        }

        int mini = 0;
        int t = s2[0] - '0';
        for (int i = 1; i < s2.length(); i++) {
            int dig2 = s2[i] - '0';
            if (dig2 == t) dig2 = 0;
            mini = mini * 10 + dig2;
        }
        cout << maxi << " " << mini;
        return maxi - mini;

    }
};