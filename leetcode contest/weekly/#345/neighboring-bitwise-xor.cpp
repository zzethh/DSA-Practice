class Solution {
public:
    bool check(vector<int>& ori, vector<int> & deri) {
        int n = ori.size();
        for (int i = 0; i < n - 1; i++) {
            int dig = ori[i] ^ ori[i + 1];
            if (dig != deri[i]) {
                return false;
            }
        }
        int dig = ori[n - 1] ^ ori[0];
        if (dig != deri[n - 1]) return false;
        return true;
    }
    bool doesValidArrayExist(vector<int>& deri) {
        int n = deri.size();
        vector<int> ori(n);
        ori[0] = 0;
        for (int i = 1; i < n - 1; i++) {
            ori[i] = ori[i - 1] ^ deri[i - 1];
        }
        ori[n - 1] = ori[0] ^ deri[n - 1];
        if (check(ori, deri)) return true;

        ori[0] = 1;
        for (int i = 1; i < n - 1; i++) {
            ori[i] = ori[i - 1] ^ deri[i - 1];
        }
        ori[n - 1] = ori[0] ^ deri[n - 1];
        if (check(ori, deri)) return true;
        return false;
    }
};