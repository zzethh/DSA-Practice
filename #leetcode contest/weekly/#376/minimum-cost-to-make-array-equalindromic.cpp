class Solution {
public:
    bool ispalin(long long n)
    {
        long long r, sum = 0, temp;
        temp = n;
        while (n > 0) {
            r = n % 10;
            sum = (sum * 10) + r;
            n = n / 10;
        }
        return temp == sum;
    }
    long long sum(vector<int> &nums, int x) {
        long long t = 0;
        for (auto it : nums) {
            t += abs(it - x);
        }
        return t;
    }
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long mid = 0;
        if (n % 2 == 0) mid = (nums[(n + 1) / 2] + nums[n / 2]) / 2;
        else mid = nums[(n) / 2];
        long long ans = 1e15;
        if (ispalin(mid)) ans = sum(nums, mid);
        long long left = -1;
        long long right = -1;
        long long r = mid + 1;
        long long l = mid - 1;
        while (left == -1 or right == -1) {
            if (right == -1 and ispalin(r)) {
                right = r;
            }
            if (left == -1 and ispalin(l)) {
                left = l;
            }
            r++;
            l--;
        }
        ans = min(ans, min(sum(nums, left), sum(nums, right)));
        return ans;
    }
};