class Solution {
public:
    int maxVowels(string st, int k) {
        unordered_set<char> s = {'a', 'e', 'i', 'o', 'u'};
        //unordered_map<char,int> m;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            // m[s[i]]++;
            if (s.find(st[i]) != s.end()) cnt++;
        }
        int maxi = cnt;
        for (int i = k; i < st.length(); i++) {
            //expand
            if (s.find(st[i]) != s.end()) cnt++;
            //contract
            if (s.find(st[i - k]) != s.end()) cnt--;

            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};