class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        int cntg = 0, lastg = 0;
        int cntp = 0, lastp = 0;
        int cntm = 0, lastm = 0;
        vector<int> pref(garbage.size() + 1, 0);
        int sum = 0;
        int i = 1;
        for (auto x : travel) {
            sum += x;
            pref[i] = sum;
            i++;
        }
        for (int i = 0; i < garbage.size(); i++) {
            string x = garbage[i];
            for (auto y : x) {
                if (y == 'M') cntm++, lastm = i;
                else if (y == 'G') cntg++, lastg = i;
                else if (y == 'P') cntp++, lastp = i;
            }
        }
        if (cntm) ans += pref[lastm] + cntm;
        if (cntg) ans += pref[lastg] + cntg;
        if (cntp) ans += pref[lastp] + cntp;
        return ans;
    }
};