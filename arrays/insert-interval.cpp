class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> v;
        if (intervals.size() == 0) {
            v.push_back(newInterval);
            return v;
        }
        int nstart = newInterval[0];
        int nend = newInterval[1];
        bool flag = true;
        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start >= nstart and start <= nend) {
                //cout<<"a";
                intervals[i][0] = min(start, nstart);
                intervals[i][1] = max(end, nend);
                flag = false;
                break;
            }
            if (nstart >= start and nstart <= end) {
                //cout<<"b";
                intervals[i][0] = min(start, nstart);
                intervals[i][1] = max(end, nend);
                flag = false;
                break;
            }
        }
        if (flag) {
            intervals.push_back(newInterval);
            sort(intervals.begin(), intervals.end());
        }
        for (auto x : intervals) {
            cout << x[0] << " " << x[1] << endl;
        }
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (end >= intervals[i][0]) {
                end = max(end, intervals[i][1]);
            }
            else {
                v.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        v.push_back({start, end});
        return v;
    }
};