class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> m;
        for (auto x : nums) {
            m[x]++;
        }
        // int mx=0;
        // for(auto x:m){
        //     if(x.second>mx) mx=x.second;
        // }
        vector<vector<int>> ans;
        while (!m.empty()) {
            vector<int> temp;
            for (auto x : m) {
                cout << x.first << ":" << m[x.first] << " ";
                temp.push_back(x.first);
                m[x.first]--;
                cout << "->";
                cout << x.first << ":" << m[x.first] << " ";
                if (m[x.first] == 0) m.erase(x.first);
            }
            cout << endl;
            ans.push_back(temp);
        }
        //vector<vector<int>> ans(mx);
        // for(int i=0;i<mx;i++){
        //     for(auto x:m){
        //         if(x.second>0){
        //             ans[i].push_back(x.first);
        //             m[x.first]--;
        //         }
        //     }
        // }
        return ans;
    }
};