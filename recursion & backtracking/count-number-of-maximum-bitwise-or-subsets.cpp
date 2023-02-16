class Solution {
public:
    vector<int> ans;
    void helper(vector<int> &nums, vector<int> v, int i, int temp) {
        if (i == nums.size()) {
            // int temp=0;
            // for(auto x:v){
            //     temp=temp|x;
            // }
            ans.push_back(temp);
            return;
        }

        helper(nums, v, i + 1, temp | nums[i]);
        helper(nums, v, i + 1, temp);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> v;
        helper(nums, v, 0, 0);
        int cnt = 0;
        sort(ans.begin(), ans.end());
        int n = ans.size() - 1;
        int k = lower_bound(ans.begin(), ans.end(), ans[n]) - ans.begin();
        cnt += (n - k + 1);
        return cnt;
    }
};