class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int maxfreq = INT_MIN;
        int ans = 0;
        for (int x : nums) {
            map[x]++;
            if (map[x] >= nums.size() / 2) {
                if (maxfreq < map[x]) {
                    maxfreq = map[x];
                    ans = x;
                }
            }
        }
        return ans;
    }
};