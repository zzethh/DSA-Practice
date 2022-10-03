class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> v(intervals.begin(), intervals.end());
        vector<int> ans;

        for (int i = 0; i < intervals.size(); i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < v.size(); i++) {
            int s = 0;
            int e = intervals.size() - 1;
            int temp = -1;
            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (intervals[mid][0] == v[i][1]) {
                    temp = intervals[mid][2];
                    break;
                }
                else if (intervals[mid][0] > v[i][1]) {
                    temp = intervals[mid][2];
                    e = mid - 1;
                }
                else {
                    s = mid + 1;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};