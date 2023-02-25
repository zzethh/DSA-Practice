class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> s;
        for (auto x : nums) {
            s.insert(x);
        }
        int ans = 1;
        while (s.count(ans)) {
            ans = ans * 2;
        }
        return ans;
    }
};