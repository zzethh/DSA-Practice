class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m = score.size();
        int n = score[0].size();
        //set<pair<int,int>,greater<pair<int,int>>> s;
        vector<pair<int, int>> v;
        for (int i = 0; i < m; i++) {
            //s.insert({score[i][k],i});
            if (k < n) v.push_back({score[i][k], i});
        }
        sort(v.begin(), v.end(), greater());
        vector<vector<int>> ans;
        for (auto x : v) {
            int idx = x.second;
            ans.push_back(score[idx]);
        }
        score = ans;
        return score;
    }
};