class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<long long> n;
        vector<long long> p;
        for (int i = 0; i < nums1.size(); i++) {
            long long diff = nums1[i] - nums2[i];
            if (diff < 0) n.push_back(abs(diff));
            if (diff > 0) p.push_back(diff);
        }

        long long sum1 = 0;
        long long sum2 = 0;
        for (auto x : n) {
            if (k != 0 and x % k != 0) return -1;
            if (k != 0)sum1 += (x / k);
        }
        for (auto x : p) {
            if (k != 0 and x % k != 0) return -1;
            if (k != 0)sum2 += (x / k);
        }

        if (k == 0 and (n.size() or p.size())) return -1;
        if (sum1 == sum2) return sum1;
        else return -1;

    }
};