class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_set<int> s;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i] % value;
            if (x < 0) x = value + x;
            mp[x]++;
        }
        int ans = 0;
        while (1) {
            if (mp[ans] == 0) return ans;
            int cnt = mp[ans];
            int k = 0;
            while (cnt--) mp[ans + (k * value)]++, k++;
            ans++;
        }
        return 0;
    }
};