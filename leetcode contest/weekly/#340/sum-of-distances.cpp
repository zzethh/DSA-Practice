class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<long long, vector<long long>> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);

        }
        vector<long long> arr(nums.size(), 0);
        for (auto x : m) {
            //int n=x.first;
            auto v = x.second;
            if (v.size() == 1) continue;
            long long right = 0;
            long long left = 0;
            for (int i = 1; i < v.size(); i++) {
                right += abs(v[i] - v[0]);
            }
            arr[v[0]] = right;
            int n = v.size();
            for (int i = 1; i < n; i++) {
                long long dis = v[i] - v[i - 1];
                right -= (long long)(n - i) * dis;
                left += (long long)(i) * dis;
                arr[v[i]] = right + left;
            }
        }
        return arr;
    }
};