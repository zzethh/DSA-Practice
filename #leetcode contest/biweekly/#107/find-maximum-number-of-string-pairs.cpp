class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int cnt = 0;
        vector<int> vis(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (vis[j]) continue;
                string rev = words[j];
                reverse(rev.begin(), rev.end());
                if (words[i] == rev) {
                    vis[j] = 1;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};