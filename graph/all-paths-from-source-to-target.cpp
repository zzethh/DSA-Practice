class Solution {
public:
    void helper(vector<vector<int>> graph, vector<vector<int>> &v, int node, vector<int> ans) {
        if (node == graph.size() - 1) {
            ans.push_back(node);
            v.push_back(ans);
            return;
        }
        ans.push_back(node);
        for (auto x : graph[node]) {
            helper(graph, v, x, ans);
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> v;
        vector<int> ans;
        helper(graph, v, 0, ans);
        return v;
    }
};