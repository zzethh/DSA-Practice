#include <bits/stdc++.h>
class node {
public:
    node* links[2];
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }
    node* get(int bit) {
        return links[bit];
    }

    void put(int bit, node* n) {
        links[bit] = n;
    }
};
class Trie {
public:
    node* root;
    Trie() {
        root = new node();
    }
    int insert(int num) {
        node* n = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!n->containsKey(bit)) {
                n->put(bit, new node());
            }
            n = n->get(bit);
        }
    }
    int getmax(int num) {
        node* n = root;
        int maxnum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (n->containsKey(1 - bit)) {
                maxnum = maxnum | (1 << i);
                n = n->get(1 - bit);
            }
            else {
                n = n->get(bit);
            }
        }
        return maxnum;
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> oq;
    int q = queries.size();
    for (int i = 0; i < q; i++) {
        oq.push_back({queries[i][1], queries[i][0], i});
    }
    sort(oq.begin(), oq.end());
    vector<int> ans(q, 0);
    int n = arr.size();
    int idx = 0;
    Trie t;
    for (int i = 0; i < q; i++) {
        int ai = oq[i][0];
        int xi = oq[i][1];
        int qidx = oq[i][2];
        while (idx < n and arr[idx] <= ai) {
            t.insert(arr[idx]);
            idx++;
        }
        if (idx == 0) ans[qidx] = -1;
        else ans[qidx] = t.getmax(xi);
    }
    return ans;
}