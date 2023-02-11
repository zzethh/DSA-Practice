class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double maxi = sum / k;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i];
            sum -= nums[i - k];
            double temp = sum / k;
            maxi = max(maxi, temp);
        }
        return maxi;
    }
};