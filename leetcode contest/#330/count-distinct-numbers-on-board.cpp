class Solution {
public:
    int distinctIntegers(int n) {
        int cnt = 1;
        unordered_set<int> s;
        s.insert(n);
        unordered_map<int, int> m;
        auto it = s.begin();
        while (it != s.end()) {
            int num = *(s.begin());
            for (int i = 1; i < num; i++) {
                if (m[i]) continue;
                if (num % i == 1) {
                    cnt++;
                    m[i]++;
                    s.insert(i);
                }
            }
            s.erase(num);
            it = s.begin();
        }
        return cnt;
    }
};