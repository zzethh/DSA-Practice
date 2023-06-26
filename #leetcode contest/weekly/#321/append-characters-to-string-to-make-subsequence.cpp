class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans = INT_MAX;
        for (int i = 0; i < s.length(); i++) {
            //int k=i;
            int j = 0;
            while (i < s.length() and j < t.length()) {
                if (s[i] == t[j]) {
                    i++;
                    j++;
                    int n = t.length();
                    ans = min(ans, n - j);
                }
                else {
                    i++;
                    int n = t.length();
                    ans = min(ans, n - j);
                    //cout<<ans<<endl;
                    //break;
                }
            }
        }
        return ans;
    }
};