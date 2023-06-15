class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        while (k--) {
            long long maxi = INT_MIN;
            long long maxidx = -1;
            for (int i = 0; i < gifts.size(); i++) {
                if (gifts[i] > maxi) {
                    maxi = gifts[i];
                    maxidx = i;
                }
            }
            long long x = floor(sqrt(maxi));
            gifts[maxidx] = x;
        }
        long long sum = 0;
        for (auto x : gifts) {
            sum += x;
        }
        return sum;
    }
};