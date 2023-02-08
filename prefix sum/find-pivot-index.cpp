class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pref;
        int sum = 0;
        for (auto x : nums) {
            sum += x;
            pref.push_back(sum);
        }
        for (int j = 0; j < nums.size(); j++) {
            if (j == 0) {
                if (pref[nums.size() - 1] - pref[0] == 0) {
                    return 0;
                }
            }
            else if (j == nums.size() - 1) {
                if (pref[j - 1] == 0) {
                    return j;
                }
            }
            else {
                if (pref[j - 1] == pref[nums.size() - 1] - pref[j]) {
                    return j;
                }
            }
        }
        return -1;
    }
};