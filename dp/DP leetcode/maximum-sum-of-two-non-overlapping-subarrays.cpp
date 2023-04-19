class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (i < firstLen) {
                sum += nums[i];
                dp1[i] = sum;
            }
            else {
                sum += nums[i] - nums[i - firstLen];
                dp1[i] = max(dp1[i - 1], sum);
            }
        }
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i + secondLen > n - 1) {
                sum += nums[i];
                dp2[i] = sum;
            }
            else {
                sum += nums[i] - nums[i + secondLen];
                dp2[i] = max(dp2[i + 1], sum);
            }
        }
        // for(auto x:dp1){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x:dp2){
        //     cout<<x<<" ";
        // }
        int ans = 0;
        for (int i = firstLen - 1; i < n - secondLen; i++) {
            ans = max(ans, dp1[i] + dp2[i + 1]);
        }

        vector<int> dp3(n, 0);
        vector<int> dp4(n, 0);
        sum = 0;
        for (int i = 0; i < n; i++) {
            if (i < secondLen) {
                sum += nums[i];
                dp3[i] = sum;
            }
            else {
                sum += nums[i] - nums[i - secondLen];
                dp3[i] = max(dp3[i - 1], sum);
            }
        }
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i + firstLen > n - 1) {
                sum += nums[i];
                dp4[i] = sum;
            }
            else {
                sum += nums[i] - nums[i + firstLen];
                dp4[i] = max(dp4[i + 1], sum);
            }
        }
        // for(auto x:dp1){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x:dp2){
        //     cout<<x<<" ";
        // }
        int ans2 = 0;
        for (int i = secondLen - 1; i < n - firstLen; i++) {
            ans2 = max(ans2, dp3[i] + dp4[i + 1]);
        }
        return max(ans, ans2);
    }
};