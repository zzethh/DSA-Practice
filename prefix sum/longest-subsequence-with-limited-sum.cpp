class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> pref;
        int sum = 0;
        for (auto x : nums) {
            sum += x;
            pref.push_back(sum);
        }
        vector<int> ans;
        for (auto x : queries) {
            int f = upper_bound(pref.begin(), pref.end(), x) - pref.begin();
            ///if(f!=nums.size()){
            ans.push_back(f);
            ///}
        }
        return ans;
    }
};