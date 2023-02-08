class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int sum = 0;
        for (auto x : gain) {
            sum += x;
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};