class Solution {
public:
    int kadane(vector<int> &nums) {
        int curr = 0;
        int maxi = INT_MIN;
        for (auto x : nums) {
            curr += x;
            maxi = max(maxi, curr);
            if (curr < 0) {
                curr = 0;
            }
        }
        return maxi;
    }
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater());
        //return kadane(nums);
        int cnt = 0;
        long long sum = 0;
        for (auto x : nums) {
            sum += x;
            if (sum > 0) cnt++;
        }
        return cnt;
    }
};