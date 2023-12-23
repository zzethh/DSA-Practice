class Solution {
public:
    long long mod = 1e9 + 7;
    long long pow(long long a, long long b, long long m) {
        long long ans = 1;
        while (b) {
            if (b % 2) {
                ans = (ans * a) % m;
                b--;
            }
            else {
                a = (a * a) % m;
                b = b / 2;
            }
        }
        return ans;
    }
    int numberOfGoodPartitions(vector<int>& nums) {
        int j = 0;
        int cnt = 0;
        int ans = 1;
        int n = nums.size();
        map<int, int> last;
        for (int i = 0; i < n; i++) {
            last[nums[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (i > j) {
                cnt++;
            }
            j = max(j, last[nums[i]]);
        }
        cnt++;
        ans = pow(2, cnt - 1, mod);
        return ans;
    }
};