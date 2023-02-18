class Solution {
public:
    vector<vector<int>> ans;
    void helper(int k, int n, int i, vector<int> temp, int sum, int idx) {
        if (sum > n) return;
        if (i > k) return;
        if (i == k and sum == n) {
            ans.push_back(temp);
            return;
        }

        for (int j = idx; j < 10; j++) {
            temp.push_back(j);
            helper(k, n, i + 1, temp, sum + j, j + 1);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        helper(k, n, 0, temp, 0, 1);
        return ans;
    }
};