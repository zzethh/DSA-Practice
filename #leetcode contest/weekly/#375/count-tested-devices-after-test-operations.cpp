class Solution {
public:
    int countTestedDevices(vector<int>& bp) {
        int cnt = 0;
        for (int i = 0; i < bp.size(); i++) {
            if (bp[i] > 0) {
                cnt++;
                for (int j = i + 1; j < bp.size(); j++) {
                    bp[j] = max(0, bp[j] - 1);
                }
            }
        }
        return cnt;
    }
};