class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int dots = n + 1;
        int cnt = 1;
        DisjointSet s(dots * dots);

        for (int i = 0; i < dots; i++) {
            for (int j = 0; j < dots; j++) {
                if (i == 0 or j == 0 or i == dots - 1 or j == dots - 1) {
                    s.unionByRank(0, i * dots + j);
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int x1 = -1;
                int y1 = -1;
                int x2 = -1;
                int y2 = -1;
                if (grid[i][j] == '/') {
                    x1 = i;
                    y1 = j + 1;
                    x2 = i + 1;
                    y2 = j;
                }
                else if (grid[i][j] == '\\') {
                    x1 = i;
                    y1 = j;
                    x2 = i + 1;
                    y2 = j + 1;
                }
                else continue;
                int rank1 = x1 * dots + y1;
                int rank2 = x2 * dots + y2;
                if (s.findUPar(rank1) == s.findUPar(rank2)) {
                    cnt++;
                }
                else {
                    if (x1 != -1) {
                        s.unionByRank(rank1, rank2);
                    }
                }
            }
        }
        return cnt;
    }
};