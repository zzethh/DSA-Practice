class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> pref(right + 1, 0);
        for (int i = 0; i < ranges.size(); i++) {
            for (int j = ranges[i][0]; j <= ranges[i][1]; j++) {
                if (j <= right) pref[j]++;
            }
        }
        for (int i = left; i <= right; i++) {
            if (pref[i] == 0) return false;
        }
        return true;
    }
};