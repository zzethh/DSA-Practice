class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        int cnta = 0;
        int cntb = 0;
        int cntc = 0;
        for (auto x : s) {
            if (x == 'a') cnta++;
            else if (x == 'b') cntb++;
            else cntc++;
        }
        unordered_map<char, int> mx;
        mx['a'] = cnta - k;
        mx['b'] = cntb - k;
        mx['c'] = cntc - k;
        if (mx['a'] < 0 or mx['b'] < 0 or mx['c'] < 0) return -1;
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_map<char, int> m;
        while (i < s.length()) {
            m[s[i]]++;
            // if(m[s[i]]>mx[s[i]]){
            //     while(j<=i and m[s[i]]>mx[s[i]]){
            //         m[s[j]]--;
            //         j++;
            //     }
            // }
            while (m[s[i]] > mx[s[i]]) {
                m[s[j]]--;
                j++;
            }
            // if(i-j+1>ans){
            //     cout<<s.substr(j,i-j+1)<<endl;
            // }
            ans = max(ans, i - j + 1);
            i++;
        }
        return n - ans;
    }
};