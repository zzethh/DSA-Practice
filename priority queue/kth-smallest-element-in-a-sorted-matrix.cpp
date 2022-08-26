class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for (int i = 0; i < matrix.size(); i++) {
            pq.push({matrix[i][0], i, 0});
        }

        int cnt = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            cnt++;
            pq.pop();
            if (top[2] + 1 < matrix[top[1]].size()) {
                pq.push({matrix[top[1]][top[2] + 1], top[1], top[2] + 1});
            }
            if (cnt == k) {
                return matrix[top[1]][top[2]];
            }

        }
        return -1;
    }
};