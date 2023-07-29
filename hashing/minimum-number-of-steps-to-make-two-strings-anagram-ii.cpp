class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v(26, 0);
        for (auto x : s) {
            v[x - 'a']++;
        }
        for (auto x : t) {
            v[x - 'a']--;
        }
        int sum = 0;
        for (auto x : v) {
            sum += abs(x);
        }
        return sum;
    }
};