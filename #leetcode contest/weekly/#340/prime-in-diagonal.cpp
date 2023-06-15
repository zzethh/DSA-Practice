class Solution {
public:
    int maxi = 0;
    bool isprime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int i = 0;
        int j = 0;
        int m = nums.size();
        int n = nums[0].size();
        while (i < m and j < n) {
            if (nums[i][j] == 1) {
                i++;
                j++;
                continue;
            }
            if (isprime(nums[i][j])) {
                maxi = max(maxi, nums[i][j]);
            }
            i++;
            j++;
        }
        i = 0;
        j = n - 1;
        while (i<m and j >= 0) {
            if (nums[i][j] == 1) {
                i++;
                j--;
                continue;
            }
            if (isprime(nums[i][j])) {
                maxi = max(maxi, nums[i][j]);
            }
            i++;
            j--;
        }
        return maxi;
    }
};