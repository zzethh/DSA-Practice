class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n + 1, 0);
        set<int> s;
        for (auto x : nums) {
            v[x]++;
            if (v[x] == 2) {
                s.insert(x);
            }
        }
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};