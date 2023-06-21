class Solution {
public:
    bool possible(vector<int> price, int k, int diff) {
        int cnt = 0;
        int prev = price[0];
        for (int i = 1; i < price.size(); i++) {
            if (abs(price[i] - prev) >= diff) {
                cnt++;
                prev = price[i];
            }
        }
        return cnt >= k - 1;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();
        int e = price[n - 1] - price[0];
        int s = 0;
        int ans = 0;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (possible(price, k, mid)) {
                ans = mid;
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        return ans;

    }
};