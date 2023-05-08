class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt = 0;
        //unordered_set<int> s;
        unordered_map<int, int> m;
        for (auto x : nums4) {
            for (auto y : nums3) {
                m[x + y]++;
            }
        }
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int target = -1 * (nums1[i] + nums2[j]);
                if (m.find(target) != m.end()) cnt += m[target];
            }
        }
        return cnt;
    }
};