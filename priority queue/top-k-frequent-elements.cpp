class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        priority_queue<vector<int>> pq;

        for (auto x : m) {
            pq.push({x.second, x.first});
        }
        vector<int> v;
        for (int i = 0; i < k; i++) {
            auto top = pq.top();
            v.push_back(top[1]);
            pq.pop();
        }
        return v;
    }
};