class graph {
    int v;
    list<int> *l;
public:
    graph(int V) {
        v = V;
        l = new list<int> [v];
    }

    void addEdge(int i, int j, bool undir = true) {
        l[i].push_back(j);
        if (undir) {
            l[j].push_back(i);
        }
    }
    void dfshelper(int source, vector<bool> &visited, vector<int> &dots) {
        if (visited[source]) {
            return;
        }
        visited[source] = 1;
        dots.push_back(source);
        for (auto x : l[source]) {
            dfshelper(x, visited, dots);
        }
    }

    void dfs(int source, vector<int> &dots) {
        vector<bool> visited(v, 0);
        dfshelper(source, visited, dots);
    }
};
class Solution {
public:
    int cnt = 0;
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        graph g(n);
        set<vector<int>> s;
        vector<bool> vis(n, 0);
        for (auto x : edges) {
            g.addEdge(x[0], x[1]);
            s.insert({x[0], x[1]});
        }
        for (int k = 0; k < n; k++) {
            if (vis[k]) continue;
            vector<int> dots;
            g.dfs(k, dots);
            for (auto x : dots) {
                vis[x] = 1;
            }
            cnt++;
            bool flag = false;
            for (int i = 0; i < dots.size(); i++) {
                for (int j = i + 1; j < dots.size(); j++) {
                    if (s.find({dots[i], dots[j]}) != s.end() or s.find({dots[j], dots[i]}) != s.end()) {
                        continue;
                    }
                    else {
                        cnt--;
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
        }
        return cnt;
        //return cnt>0?cnt:0;
    }
};