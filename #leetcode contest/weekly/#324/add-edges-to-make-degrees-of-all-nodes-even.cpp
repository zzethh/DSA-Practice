class Solution {
public:
    bool check(int a, int b, vector<unordered_set<int>> &adj) {
        if (adj[a].find(b) == adj[a].end()) return true;
        return false;
    }
    bool isPossible(int n, vector<vector<int>>& edges) {

        vector<unordered_set<int>> adj(n + 1);

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }


        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (adj[i].size() % 2 != 0) {
                v.push_back(i);
                cout << i << " ";
            }
        }
        cout << endl;

        if (v.size() == 0) return true;
        if (v.size() > 4 or v.size() == 3) {
            return 0;
        }

        if (v.size() == 4) {
            bool flag1 = check(v[0], v[1], adj) and check(v[2], v[3], adj);
            bool flag2 = check(v[0], v[2], adj) and check(v[1], v[3], adj);
            bool flag3 = check(v[0], v[3], adj) and check(v[1], v[2], adj);
            //cout<<flag1<<flag2<<flag3;
            return (flag1 or flag2 or flag3);

            //}
        }

        if (v.size() == 2) {
            bool flag = check(v[0], v[1], adj);
            if (flag) return true;
            if (!flag) {
                for (int i = 1; i <= n; i++) {
                    if (v[0] != i && v[1] != i && adj[v[0]].find(i) == adj[v[0]].end() && adj[v[1]].find(i) == adj[v[1]].end()) {
                        return 1;
                    }
                }
            }
        }

        return 0;

    }
};