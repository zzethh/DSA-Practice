class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int maxi = -1;
        int ans = -1;
        for (int i = 0; i < divisors.size(); i++) {
            int score = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] % divisors[i] == 0) score++;
            }
            if (score > maxi) {
                maxi = score;
                ans = divisors[i];
            }
            else if (score == maxi) {
                if (divisors[i] < ans) {
                    ans = divisors[i];
                }
            }
        }
        return ans;
    }
};