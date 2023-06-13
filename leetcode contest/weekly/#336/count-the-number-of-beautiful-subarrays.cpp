class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        vector<long long> pref;
        unordered_map<long long, long long> m;
        long long y = 0;
        long long cnt = 0;
        pref.push_back(0);
        m[0]++;
        for (auto x : nums) {
            y = y ^ x;
            if (m.find(y) != m.end()) {
                cnt += m[y];
            }
            m[y]++;
            pref.push_back(y);
        }
        return cnt;
    }
};