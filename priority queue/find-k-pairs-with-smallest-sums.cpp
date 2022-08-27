class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<vector<int>, bool> visited;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> ans;
        pq.push({nums1[0] + nums2[0], 0, 0});
        while (!pq.empty() && ans.size() < k) {
            auto temp = pq.top();
            pq.pop();
            int i = temp[1];
            int j = temp[2];
            if (visited[ {i, j}]) {
                continue;
            }

            visited[ {i, j}] = true;
            ans.push_back({nums1[temp[1]], nums2[temp[2]]});

            if (i + 1 < nums1.size()) {
                pq.push({nums1[i + 1] + nums2[j], i + 1, j});
            }
            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1}) ;
            }
        }
        return ans;
    }
};