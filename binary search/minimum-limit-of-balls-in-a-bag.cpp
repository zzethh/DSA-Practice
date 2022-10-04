class Solution {
public:
    bool check(int mid, vector<int> nums, int o) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt = cnt + (nums[i] / mid);
            if (nums[i] % mid == 0) cnt--;
        }

        return cnt <= o;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int s = 1;
        int e = INT_MAX;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (check(mid, nums, maxOperations)) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return ans;
    }
};