class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int dig1 = INT_MAX;
        int dig2 = INT_MAX;
        unordered_map<int, int> m;
        for (auto x : nums1) {
            m[x]++;
            dig1 = min(dig1, x);
        }
        for (auto y : nums2) {
            m[y]++;
            dig2 = min(dig2, y);
        }
        int ans = INT_MAX;
        for (auto x : m) {
            if (x.second >= 2) {
                ans = min(ans, x.first);
            }
        }
        if (ans != INT_MAX) return ans;
        if (dig2 > dig1) return dig1 * 10 + dig2;
        return dig2 * 10 + dig1;
    }
};