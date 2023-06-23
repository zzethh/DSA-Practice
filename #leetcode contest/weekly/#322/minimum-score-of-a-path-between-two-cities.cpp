class Solution {
public:
    list<pair<int, int> > *l2;
    int ans2 = -1;
    void dfshelper(int source, int dest, vector<bool> &visited, int &ans) {
        // if(source==dest){
        //     ans2=ans;
        //     return;
        // }
        if (visited[source]) {
            return;
        }
        visited[source] = 1;
        //cout << source << endl;
        for (auto x : l2[source]) {
            ans = min(ans, x.first);
            dfshelper(x.second, dest, visited, ans);
        }
    }

    int dfs(int start, int dest, int n) {
        vector<bool> visited(n + 1, 0);
        int ans = INT_MAX;
        dfshelper(start, dest, visited, ans);
        //return ans2;
        if (visited[dest] == 1) {
            return ans;
        }
        return -1;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        l2 = new list<pair<int, int> >[n + 1];
        for (auto t : roads) {
            int x = t[0];
            int y = t[1];
            int wt = t[2];
            l2[x].push_back({wt, y});
            l2[y].push_back({wt, x});
        }

        return dfs(1, n, n);
    }
};