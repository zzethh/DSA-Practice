class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int cnt = 0;
        int prod = 1;
        for (int i = 0; i < nums.size(); i++) {
            prod = nums[i];
            for (int j = i; j < nums.size(); j++) {
                prod = __gcd(prod, nums[j]);
                if (prod == k) {
                    cnt++;
                }
                if (prod < k) {
                    break;
                }
            }
        }
        return cnt;
    }
};