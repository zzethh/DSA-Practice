class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = nums.size() - 1; i >= 2; i--) {
            int l = 0;
            int h = i - 1;
            while (l < h) {
                if (nums[l] + nums[h] > nums[i]) {
                    cnt = cnt + h - l;
                    h--;
                }
                else {
                    l++;
                }
            }
        }
        return cnt;
    }
};