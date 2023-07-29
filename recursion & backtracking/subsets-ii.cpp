class Solution {
public:
    set<vector<int>> ans;
    void helper(vector<int> &arr, vector<int> v, int i) {
        if (i == arr.size()) {
            sort(v.begin(), v.end());
            ans.insert(v);
            return ;
        }
        v.push_back(arr[i]);
        helper(arr, v, i + 1);
        v.pop_back();
        helper(arr, v, i + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        helper(nums, v, 0);
        vector<vector<int>> a(ans.begin(), ans.end());
        return a;
    }
};