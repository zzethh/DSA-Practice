class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> &v, int target, vector<int> temp, int i) {
        if (target < 0) return;

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int k = i; k < v.size(); k++) {
            temp.push_back(v[k]);
            helper(v, target - v[k], temp, k);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        helper(candidates, target, temp, 0);
        return ans;
    }
};