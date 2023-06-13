class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> v;
        for (int i = 0; i < nums2.size(); i++) {
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.begin(), v.end(), greater<vector<int>>());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long currSum = 0;
        long long maxSum = INT_MIN;
        for (int i = 0; i < v.size(); i++) {
            int x = v[i][1];
            long long min = v[i][0];
            pq.push(x);
            currSum += x;

            if (pq.size() > k) {
                currSum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                maxSum = max(maxSum, currSum * min);
            }

        }
        return maxSum;

    }
};