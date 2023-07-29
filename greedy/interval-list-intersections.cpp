class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        vector<vector<int>> ans;
        int j = 0;
        int i = 0;
        while (i < first.size() and j < second.size()) {
            if (second[j][0] <= first[i][1]) {
                int start = max(first[i][0], second[j][0]);
                int end = min(first[i][1], second[j][1]);
                if (end >= start) ans.push_back({start, end});
                if (first[i][1] < second[j][1]) {
                    i++;
                }
                else if (second[j][1] < first[i][1]) {
                    j++;
                }
                else {
                    i++;
                    j++;
                }
                continue;
            }
            else if (second[j][0] > first[i][1]) {
                i++;
                continue;
            }
            else if (first[i][0] > second[j][1]) {
                j++;
                continue;
            }
            i++;
            j++;
        }
        return ans;
    }
};