class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> m(21, 0);
        m[bills[0]]++;
        for (int i = 1; i < bills.size(); i++) {
            int x = bills[i];
            m[x]++;
            if (x == 20) {
                if (m[10] >= 1 and m[5] >= 1) {
                    m[10]--;
                    m[5]--;
                }
                else if (m[5] >= 3) {
                    m[5] -= 3;
                    continue;
                }
                else return false;
            }
            else if (x == 10) {
                if (m[5] >= 1) {
                    m[5] -= 1;
                    continue;
                }
                else return false;
            }
        }

        return true;
    }
};