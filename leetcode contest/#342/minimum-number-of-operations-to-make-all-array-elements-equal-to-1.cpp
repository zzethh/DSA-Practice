class Solution {
public:
    int gcd(int a, int b) {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }

    int minOperations(vector<int>& nums) {
        int cnt1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt1 += nums[i] == 1 ? 1 : 0;
        }
        if (cnt1 > 0) {
            return nums.size() - cnt1;
        }
        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int curr = 0;
            for (int j = i; j < nums.size(); j++) {
                curr = gcd(curr, nums[j]);
                if (curr == 1) {
                    int cmp = j - i + nums.size() - 1;
                    mini = min(mini, cmp);
                    break;
                }
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};