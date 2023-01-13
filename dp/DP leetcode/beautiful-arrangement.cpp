class Solution {
public:
    void helper(int n, vector<int> &v, int i, int &cnt) {
        if (i == n) {
            cnt++;
            return;
        }
        // int cnt=0;
        for (int j = i; j < n; j++) {
            swap(v[i], v[j]);
            if (v[i] % (i + 1) == 0 or (i + 1) % v[i] == 0) helper(n, v, i + 1, cnt);
            swap(v[i], v[j]);
        }
        // return cnt;
    }
    int countArrangement(int n) {
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            v[i] = i + 1;
        }
        int cnt = 0;
        helper(n, v, 0, cnt);
        return cnt;
    }
};