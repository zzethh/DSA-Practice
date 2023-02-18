class Solution {
public:
    vector<vector<int>> ans;
    void helper(int k, int n, int i, vector<int> temp, int sum, unordered_map<int, int> m) {
        if (sum > n) return;
        if (i > k) return;
        if (i == k and sum == n) {
            ans.push_back(temp);
            return;
        }

        for (int j = 1; j < 10; j++) {
            if (m.count(j)) continue;
            m[j]++;
            temp.push_back(j);
            helper(k, n, i + 1, temp, sum + j, m);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        unordered_map<int, int> m;
        helper(k, n, 0, temp, 0, m);
        return ans;
    }
};