class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> v;
        for (int i = 0; i < points.size(); i++) {
            int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            v.push_back({distance, points[i][0], points[i][1]});
        }

        priority_queue<vector<int>> pq(v.begin(), v.begin() + k);
        for (int i = k; i < v.size(); i++) {
            auto top = pq.top();
            if (top[0] > v[i][0]) {
                pq.pop();
                pq.push({v[i][0], v[i][1], v[i][2]});
            }
        }

        vector<vector<int>> b;

        while (!pq.empty()) {
            auto top = pq.top();
            b.push_back({top[1], top[2]});
            pq.pop();
        }

        return b;
    }
};