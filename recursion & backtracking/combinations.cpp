class Solution {
public:
    vector<vector<int>> ans;
    void helper(int n, int k, int idx, vector<int> temp) {
        if (temp.size() > k) return;
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i <= n; i++) {
            temp.push_back(i);
            helper(n, k, i + 1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        helper(n, k, 1, temp);
        return ans;
    }
};