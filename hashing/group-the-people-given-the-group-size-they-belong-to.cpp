class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        map<int, vector<int>> m;
        for (int i = 0; i < g.size(); i++) {
            m[g[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for (auto x : m) {
            if (x.second.size() > x.first) {
                int cnt = 0;
                //cout<<x.second.size()-x.first<<endl;
                while (cnt <= x.second.size() - x.first) {
                    vector<int> v;
                    // cout<<cnt;
                    // cout<<cnt+x.first;
                    int i = 0;
                    for (i = cnt; i < cnt + x.first; i++) {
                        v.push_back(x.second[i]);
                        //cout<<"hello";
                    }
                    cnt = i;
                    ans.push_back(v);
                }
                continue;
            }
            ans.push_back(x.second);
        }
        return ans;
    }
};