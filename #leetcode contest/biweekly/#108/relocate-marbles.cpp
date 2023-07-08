class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> s;
        for (auto x : nums) {
            s.insert(x);
        }
        // for(auto x:s){
        //     cout<<x;
        // }
        for (int i = 0; i < moveFrom.size(); i++) {
            //if(s.find(moveFrom[i])!=s.end()){
            s.erase(moveFrom[i]);
            s.insert(moveTo[i]);
            // }
        }
        vector<int> ans;
        for (auto x : s) {
            ans.push_back(x);
        }
        return ans;
    }
};