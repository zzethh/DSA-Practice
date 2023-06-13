class Solution {
public:
    // int ans=0;
    // void helper(unordered_set<int> &se,int i,int max,vector<int> &v,int cnt){
    //     if(i>=v.size()){
    //         if(cnt>ans){
    //             ans=cnt;
    //         }
    //         return;
    //     }
    //     auto f=se.find(v[i]);
    //     if(f==se.end() and max-v[i]>=0){
    //         helper(se,i+1,max-v[i],v,cnt+1);
    //     }
    //     helper(se,i+1,max,v,cnt);
    // }
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> se;
        for (auto x : banned) {
            se.insert(x);
        }
        int sum = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            auto f = se.find(i);
            if (f == se.end() and sum + i <= maxSum) {
                cnt++;
                sum += i;
            }
        }
        return cnt;
    }
};