class Solution {
public:
    int ans;
    void helper(vector<int> &c, int i, vector<int> &b) {
        int k = b.size();
        if (i >= c.size()) {
            int temp = INT_MIN;
            for (auto x : b) {
                temp = max(temp, x);
            }
            ans = min(ans, temp);
            return;
        }

        for (int j = 0; j < k; j++) {
            b[j] += c[i];
            helper(c, i + 1, b);
            b[j] -= c[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> bag(k, 0);
        ans = INT_MAX;
        helper(cookies, 0, bag);
        return ans;
    }
};