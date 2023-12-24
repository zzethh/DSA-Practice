class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int selected = 0;
        int sum = 0;
        int cnt = 0;
        if (nums[0] != 0) cnt++;
        nums.push_back(INT_MAX);
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i + 1 > nums[i] and i + 1 < nums[i + 1]) {
                cnt++;
            }
        }
        return cnt;
    }
};