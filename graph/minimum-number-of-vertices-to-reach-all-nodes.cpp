class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        map<int, int> m;
        for (auto x : edges) {
            m[x[1]]++;
        }

        vector<int> v;

        for (int i = 0; i < n; i++) {
            if (!m[i]) {
                v.push_back(i);
            }
        }

        return v;
    }
};