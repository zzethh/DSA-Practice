class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> s;
        for (auto x : nums) {
            s.insert(x);
        }
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            int x = *it;
            if (x <= 0) return -1;
            int y = (-1) * x;
            if (s.find(y) != s.end()) return x;
        }
        return -1;
    }
};