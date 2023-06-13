class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) return i;
        }
        return -1;
    }
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx1 = search(nums, 1);
        int ans = idx1;
        while (idx1 != 0) {
            swap(nums[idx1], nums[idx1 - 1]);
            idx1--;
        }
        int idx2 = search(nums, n);
        int cnt = 0;
        while (idx2 != n - 1) {
            swap(nums[idx2], nums[idx2 + 1]);
            idx2++;
            cnt++;
        }
        return cnt + ans;
    }
};