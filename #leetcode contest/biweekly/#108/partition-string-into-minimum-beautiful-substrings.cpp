class Solution {
public:
    int ans = INT_MAX;
    bool isPower(int x, long long int y)
    {
        // The only power of 1 is 1 itself
        if (x == 1)
            return (y == 1);

        // Repeatedly compute power of x
        long long pow = 1;
        while (pow < y)
            pow *= x;

        // Check if power of x becomes y
        return (pow == y);
    }

    bool divi(string s) {
        long long pow = 1;
        long long sum = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int dig = s[i] - '0';
            sum += pow * dig;
            pow = pow * 2;
        }
        // int n = (int)(log(sum) / log(5));
        // if ((int)(pow(5,n) + 1e-9) == sum) return true;
        if (isPower(5, sum)) return true;
        return false;
    }
    bool nonzero(string s) {
        bool flag = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0' and flag) {
                return false;
            }
            else if (s[i] == '1') {
                flag = false;
            }
        }
        return true;
    }
    void helper(string s, int cnt) {
        if (s.length() == 0) {
            ans = min(ans, cnt);
            //cout<<endl;
        }
        for (int j = 0; j < s.length(); j++) {
            if (divi(s.substr(0, j + 1)) and nonzero(s.substr(0, j + 1))) {
                //cout<<s.substr(0,j+1)<<" ";
                helper(s.substr(j + 1), cnt + 1);
            }
        }
    }
    int minimumBeautifulSubstrings(string s) {
        int cnt = 0;
        helper(s, cnt);
        string t = "1";
        //cout<<divi(t)<<" "<<nonzero(t);
        // if(ans==1) return -1;
        if (ans == INT_MAX) return -1;
        return ans;
    }
};