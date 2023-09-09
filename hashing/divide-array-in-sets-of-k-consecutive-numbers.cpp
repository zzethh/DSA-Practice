class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> m;
        for (auto x : nums) {
            m[x]++;
        }
        while (!m.empty()) {
            int key = m.begin()->first;
            for (int i = key; i < key + k; i++) {
                if (m.find(i) == m.end()) {
                    return false;
                }
                else {
                    m[i]--;
                    if (m[i] == 0) {
                        m.erase(i);
                    }
                }
            }
        }
        return true;
    }
};