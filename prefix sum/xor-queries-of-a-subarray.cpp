class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int temp = 0;
        vector<int> pref;
        pref.push_back(0);
        for (auto x : arr) {
            temp = temp ^ x;
            pref.push_back(temp);
        }
        vector<int> ans;
        for (auto x : queries) {
            int k = pref[x[1] + 1] ^ pref[x[0]];
            ans.push_back(k);
        }
        return ans;
    }
};