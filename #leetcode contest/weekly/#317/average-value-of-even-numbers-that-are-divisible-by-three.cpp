class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int cnt = 0;
        for (auto x : nums) {
            if (x % 3 == 0 and x % 2 == 0) {
                sum += x;
                cnt++;
            }
        }
        if (cnt != 0) return sum / cnt;
        return 0;
    }
};