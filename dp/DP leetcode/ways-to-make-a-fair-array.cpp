class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int odd = 0;
        int even = 0;
        vector<vector<int>> left;
        vector<vector<int>> right(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 != 0) {
                odd += nums[i];
            }
            if (i % 2 == 0) {
                even += nums[i];
            }
            left.push_back({odd, even});
        }

        odd = 0;
        even = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i % 2 != 0) {
                odd += nums[i];
            }
            if (i % 2 == 0) {
                even += nums[i];
            }
            right[i] = {odd, even};
        }

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int evenSum;
            int oddSum;
            if (i % 2 == 0) {
                evenSum = right[i][0] + left[i][1] - x;
                oddSum = right[i][1] + left[i][0] - x;
                if (oddSum == evenSum) cnt++;
            }
            else {
                evenSum = right[i][0] + left[i][1] - x;
                oddSum = right[i][1] + left[i][0] - x;
                if (oddSum == evenSum) cnt++;
            }
        }

        return cnt;
    }
};