class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        for (auto x : nums) {
            maxi = max(maxi, x);
        }
        int score = 0;
        for (int i = 1; i <= k; i++) {
            score += maxi;
            maxi = maxi + 1;
        }
        return score;
    }
};