#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<ll> cnt(31);
        for (auto i : nums) {
            int pwr = 0;
            while (i % 2 == 0) pwr ++, i /= 2;
            cnt[pwr] ++;
        }

        ll carry = 0, result = 0;

        for (int i = 0; i < 31; i ++) {
            if ((target & (1 << i)) == 0) {
                carry += cnt[i] * (1 << i);
                continue;
            }

            if (cnt[i] > 0) {
                cnt[i] --;
                carry += cnt[i] * (1 << i);
                continue;
            }
            if (carry >= (1 << i)) {
                carry -= (1 << i);
                continue;
            }

            bool found = false;
            for (int j = i + 1; j < 31; j ++) {
                if (cnt[j] == 0) continue;
                found = true;

                for (int k = j; k > i; k --) {
                    cnt[k] --;
                    cnt[k - 1] += 2;
                    result ++;
                }
                break;
            }
            if (!found) return -1;
            i --;
        }

        return result;
    }
};