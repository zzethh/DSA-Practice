class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int, int> m;
        int j = 0;
        int sum = 0;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            sum += nums[i];
            while (j<i and m[nums[i]]>1) {
                sum -= nums[j];
                m[nums[j]]--;
                j++;
            }
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};