class Solution {
public:
    int sum(int n) {
        int sum = 0;
        while (n > 0) {
            int x = n % 10;
            sum += x;
            n = n / 10;
        }
        return sum;
    }
    int differenceOfSum(vector<int>& nums) {
        int element = 0;
        for (auto x : nums) {
            element += x;
        }
        int digi = 0;
        for (auto y : nums) digi += sum(y);

        return abs(digi - element);
    }
};