#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            rank[i] = i;
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
            parent[ulp_v] = ulp_u;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_u] = ulp_v;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet d(26);
        for (int i = 0; i < s1.length(); i++) {
            d.unionByRank(s1[i] - 'a', s2[i] - 'a');
        }
        string s = "";
        for (auto x : baseStr) {
            char y = d.findUPar(x - 'a') + 'a';
            s = s + y;
        }

        return s;
    }
};