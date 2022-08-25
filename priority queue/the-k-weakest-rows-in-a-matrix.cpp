class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < mat.size(); i++) {
            int soldiers = count(mat[i].begin(), mat[i].end(), 1);
            pq.push({soldiers, i});
        }

        vector<int> v;

        for (int i = 0; i < k; i++) {
            auto top = pq.top();
            v.push_back(top[1]);
            pq.pop();
        }
        return v;
    }
};