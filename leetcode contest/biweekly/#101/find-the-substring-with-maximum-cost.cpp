class Solution {
public:
    int kadane(vector<int> &v) {
        int sum = 0;
        int maxi = INT_MIN;
        for (auto it : v) {
            sum += it;
            maxi = max(sum, maxi);
            if (sum < 0) sum = 0;
        }
        return maxi;
    }
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> m;
        char c = 'a';
        m[c] = 1;
        for (int i = 1; i < 26; i++) {
            c++;
            m[c] = i + 1;
        }
        for (int i = 0; i < chars.size(); i++) {
            m[chars[i]] = vals[i];
        }
        // for(int i=0;i<s.length();i++){
        //     for(int j=1;j<s.length()-i+1;j++){
        //         string t = s.substr(i,j);
        //         int sum=0;
        //         for(auto x:t){
        //             // int f=chars.find(x);
        //             // if(f!=-1){
        //             //     sum+=vals[f];
        //             // }
        //             // else{
        //             //     sum+=(x-'a'+1);
        //             // }
        //             sum+=m[x];
        //         }
        //         ans=max(sum,ans);
        //     }
        // }
        // if(ans<0) return 0;
        vector<int> v;
        for (auto x : s) {
            v.push_back(m[x]);
        }
        int ans = kadane(v);
        if (ans < 0) return 0;
        return ans;
    }
};