class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        if (nums.size() == 0) return 0;
        for (int i = 0; i < nums.size(); i++) {
            int j = i;
            int cnt = 0;
            if (nums[i] == 0) {
                if (j < nums.size()) j++;
                while (j < nums.size() and nums[j] == 1) {
                    j++;
                    cnt++;
                }
            }
            else {
                while (j < nums.size() and  nums[j] == 1) {
                    cnt++;
                    j++;
                }
                if (j == nums.size()) {
                    cnt--;
                    maxi = max(maxi, cnt);
                    break;
                }
                if (j < nums.size()) j++;
                while (j < nums.size() and nums[j] == 1) {
                    j++;
                    cnt++;
                }
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int i = 0, j, k = 1, res = 0;
        for (j = 0; j < A.size(); ++j) {
            if (A[j] == 0) {
                k--;
            }
            while (k < 0) {
                if (A[i] == 0) {
                    k++;
                }
                i++;
            }
            res = max(res, j - i);
        }
        return res;
    }
};