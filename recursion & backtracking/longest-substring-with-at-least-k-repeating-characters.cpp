class Solution {
public:
    int helper(string s, int start, int end, int k) {
        if (end - start < k) return 0;
        map<char, int> m;
        for (int i = start; i < end; i++) {
            m[s[i]]++;
        }
        for (int i = start; i < end; i++) {
            if (m[s[i]] < k) {
                int j = i + 1;
                while (j < end and m[s[j]] < k) {
                    j++;
                }
                return max(helper(s, start, i, k), helper(s, j, end, k));
            }
        }
        return end - start;
    }
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.length(), k);
    }
};