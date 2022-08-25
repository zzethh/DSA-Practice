class Solution {
public:
    bool static compare(vector<int> a, vector<int> b) {
        if (a[1] < b[1]) {
            return true;
        }
        return false;
    }

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }

        for (int i = k; i < nums.size(); i++) {
            auto top = pq.top();
            if (top[0] < nums[i]) {
                pq.pop();
                pq.push({nums[i], i});
            }
        }

        vector<vector<int>> v;

        while (!pq.empty()) {
            auto top = pq.top();
            v.push_back(top);
            pq.pop();
        }

        sort(v.begin(), v.begin() + k, compare);
        vector<int> b;
        for (auto x : v) {
            b.push_back(x[0]);
        }
        return b;
    }
};