
class graph {
    int v;
    list<int> *l;
public:
    graph(int x) {
        v = x;
        l = new list<int>[v];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
    }

    int minDistance(int src, int dest) {
        vector<bool> visited(v, 0);
        vector<int> dist(v, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        visited[src] = 1;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            for (auto x : l[f]) {
                if (!visited[x]) {
                    q.push(x);
                    visited[x] = 1;
                    dist[x] = dist[f] + 1;
                }
            }
        }

        return dist[dest];
    }
};

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        graph g((n * n) + 1);

        bool flag = 1;
        int number = 1;

        vector<int> board2((n * n) + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (flag) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] != -1) {
                        board2[number] = board[i][j];
                    }
                    number++;
                }
            }
            else {
                for (int j = n - 1; j >= 0; j--) {
                    if (board[i][j] != -1) {
                        board2[number] = board[i][j];
                    }
                    number++;
                }
            }
            flag = !flag;
        }

        for (int u = 1; u < n * n; u++) {
            for (int dice = 1; dice <= 6; dice++) {
                int v = u + dice;
                if (v <= n * n and board2[v] != 0) v = board2[v];
                if (v <= n * n) {
                    g.addEdge(u, v);
                }
            }
        }
        return g.minDistance(1, n * n);
    }
};