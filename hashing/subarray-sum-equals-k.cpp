class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //vector<int> pref;
        int sum = 0;
        map<int, int> m;
        int cnt = 0;
        m[sum]++;
        for (auto x : nums) {
            sum += x;
            if (m.find(sum - k) != m.end()) {
                cnt += m[sum - k];
            }
            m[sum]++;
        }

        return cnt;

    }
};