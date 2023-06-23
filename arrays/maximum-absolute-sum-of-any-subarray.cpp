class Solution {
public:
    int maxAbsoluteSum(vector<int>& v) {
        int sum = 0;
        int maxi = INT_MIN;
        for (auto it : v) {
            sum += it;
            maxi = max(sum, maxi);
            if (sum < 0) sum = 0;
        }
        sum = 0;
        for (auto it : v) {
            sum += it;
            maxi = max(abs(sum), maxi);
            if (sum > 0) sum = 0;
        }
        return maxi;
    }
};