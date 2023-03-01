class Solution {
public:
    int cnt = 0;
    vector<char> v = {'a', 'e', 'i', 'o', 'u'};

    // void helper(vector<char> &v,int k,string s,int n){
    //     if(s.size()==n){
    //         cnt++;
    //         return;
    //     }
    //     for(int i=k;i<v.size();i++){
    //         helper(v,i,s+v[i],n);
    //     }
    // }
    int countVowelStrings(int n) {
        // vector<char> v={'a','e','i','o','u'};
        // string s="";
        // helper(v,0,s,n);
        // return cnt;
        vector<int> dp(5, 1);
        int ans = 0;

        while (--n) {
            for (int i = 3; i >= 0; i--) {
                dp[i] += dp[i + 1];
            }
        }

        for (auto x : dp) ans += x;

        return ans;
    }
};