class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int i = 0;
        int j = 0;
        int maxi = 0;
        while (i < s.length() and j < s.length()) {
            m[s[i]]++;
            if (m[s[i]] == 2) {
                while (j <= i and s[j] != s[i]) {
                    cout << s[j] << " " << j << " ";
                    m[s[j]]--;
                    j++;
                }
                cout << endl;
                m[s[i]]--;
                j++;
            }
            maxi = max(maxi, i - j + 1);
            i++;
        }
        return maxi;
    }
};