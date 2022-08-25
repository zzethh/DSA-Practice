class Solution {
public:

    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                continue;
            } else {
                cnt++;
                int temp = nums[i];
                for (int j = i; j < nums.size(); j++) {
                    nums[j] = nums[j] - temp;
                }
            }
        }
        return cnt;
    }
};