class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        unordered_map<int, int> m;
        for (int i = 0; i < nums1.size(); i++) {
            m[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++) {
            if (m[nums2[i]]) {
                m[nums2[i]]--;
                s.insert(nums2[i]);
            }
        }
        vector<int> v(s.begin(), s.end());
        return v;
    }
};