class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        ///long long n=0;
        long long remainder = 0;
        for (auto x : word) {
            int dig = x - '0';
            remainder = (remainder * 10 + dig) % m;
            if (remainder % m == 0) {
                ans.push_back(1);
            }
            else ans.push_back(0);
        }
        return ans;
    }
};