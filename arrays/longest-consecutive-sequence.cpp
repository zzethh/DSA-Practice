class Solution {
public:
    bool isHead(int y, unordered_set<int> &s) {
        if (s.find(y - 1) == s.end()) {
            return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto x : nums) {
            s.insert(x);
        }

        int maxi = INT_MIN;
        for (auto y : nums) {
            if (isHead(y, s)) {
                int len = 0;
                while (s.find(y) != s.end()) {
                    y = y + 1;
                    len++;
                }
                maxi = max(len, maxi);
            }
        }
        return maxi == INT_MIN ? 0 : maxi;
    }
};