class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        vector<int> pref;
        for (auto x : nums) {
            sum += x;
            pref.push_back(sum);
        }

        int mini = INT_MAX;
        for (auto x : pref) {
            mini = min(mini, x);
        }
        if (mini > 0) return 1;
        return abs(mini) + 1;
    }
};