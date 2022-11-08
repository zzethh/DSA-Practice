class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> m;
        for (auto x : edges) {
            m[x[0]]++;
            m[x[1]]++;
        }
        int max = INT_MIN;
        for (auto x : m) {
            if (x.second > max) {
                max = x.first;
            }
        }

        return max;
    }
};