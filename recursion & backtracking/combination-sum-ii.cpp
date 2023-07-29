class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> &v, int target, vector<int> &temp, int i) {
        if (target < 0) return;

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int k = i; k < v.size(); k++) {
            if (k != i and v[k] == v[k - 1]) continue;
            temp.push_back(v[k]);
            helper(v, target - v[k], temp, k + 1);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<int> temp;
        sort(c.begin(), c.end());
        helper(c, target, temp, 0);
        return ans;
    }
};