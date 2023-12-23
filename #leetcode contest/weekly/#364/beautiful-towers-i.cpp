class Solution {
public:
    long long summ(vector<int> &maxh, int maxi, int maxele) {
        long long sum = 0;
        int n = maxh.size();
        vector<int> v(n);
        v[maxele] = maxi;
        for (int i = maxele + 1; i < maxh.size(); i++) {
            int x = min(maxh[i], v[i - 1]);
            //cout<<x<<" ";
            sum += x;
            v[i] = x;
        }
        for (int i = maxele - 1; i >= 0; i--) {
            int x = min(maxh[i], v[i + 1]);
            sum += x;
            v[i] = x;
        }
        return sum + maxi;
    }

    long long maximumSumOfHeights(vector<int>& maxh) {
        int maxele = -1;
        long long maxi = INT_MIN;
        int n = maxh.size();
        vector<pair<int, int>> t;
        for (int i = 0; i < maxh.size(); i++) {
            if (maxh[i] >= maxi) {
                maxi = maxh[i];
                maxele = i;
                t.push_back({maxi, maxele});
            }
        }
        long long ans = INT_MIN;
        for (int i = 0; i < maxh.size(); i++) {
            //ans=max(ans,summ(maxh,x.first,x.second));
            ans = max(ans, summ(maxh, maxh[i], i));
        }
        return ans;

    }
};