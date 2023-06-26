class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int, int> pickup;
        unordered_map<int, int> leave;
        for (auto x : trips) {
            pickup[x[1]] += x[0];
            leave[x[2]] += x[0];
        }
        int cnt = 0;
        for (int i = 0; i <= 1000; i++) {
            cnt += pickup[i];
            cnt -= leave[i];
            if (cnt > capacity or cnt < 0) return false;
        }
        return true;
    }
};