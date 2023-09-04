class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int cnt = 0;
        set<int> s;
        for (auto x : nums) {
            s.insert(x);
        }
        for (int i = 0; i < nums.size(); i++) {
            set<int> check;
            for (int j = i; j < nums.size(); j++) {
                check.insert(nums[j]);
                if (check.size() == s.size()) cnt++;
            }
        }
        return cnt;
    }
};