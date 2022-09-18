class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            q.push(i);
            while (!q.empty() and freq[s[q.front()] - 'a'] > 1) {
                q.pop();
            }
        }

        return q.empty() ? -1 : q.front();
    }
};