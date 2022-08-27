class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        map<pair<int, int>, bool> m;

        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;

        int n = arr.size() - 1;
        pq.push({(double)arr[0] / arr[n], {0, n}});
        vector<vector<int>> ans;
        while (!pq.empty() && ans.size() < k) {
            auto temp = pq.top();
            pq.pop();
            int i = temp.second.first;
            int j = temp.second.second;
            if (m[ {i, j}]) {
                continue;
            }
            m[ {i, j}] = true;
            ans.push_back({arr[i], arr[j]});
            if (i + 1 < j) {
                pq.push({(double)arr[i + 1] / arr[j], {i + 1, j}});
            }
            if (j - 1 > i) {
                pq.push({(double)arr[i] / arr[j - 1], {i, j - 1}});
            }
        }
        return ans.back();
    }
};