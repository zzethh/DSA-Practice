class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int maxele;
        int freq;
        map<int, int> m;
        for (auto x : nums) {
            m[x]++;
        }
        for (auto x : m) {
            if (2 * x.second > n) {
                maxele = x.first;
                freq = x.second;
                break;
            }
        }

        int lfreq = 0;
        int rfreq = freq;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxele) {
                lfreq++;
                rfreq--;
            }
            if (2 * lfreq > i + 1 and 2 * rfreq > n - i - 1) {
                return i;
            }
        }

        return -1;
    }
};