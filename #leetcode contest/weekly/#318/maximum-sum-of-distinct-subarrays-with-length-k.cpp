class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // unordered_set<int> s;
        unordered_map<long long, long long> m;
        vector<long long> pref;
        // pref.push_back(0);
        long long sum = 0;
        for (auto x : nums) {
            sum += x;
            // cout<<sum<<" ";
            pref.push_back(sum);
        }
        for (int i = 0; i < k; i++) {
            //s.insert(nums[i]);
            m[nums[i]]++;
        }
        long long ans = 0;
        // cout<<endl;
        if (m.size() == k) {
            ans = pref[k - 1];
            //cout<<ans<<endl;
        }
        for (int i = k; i < nums.size(); i++) {
            // s.erase(nums[i-k]);
            //s.insert(nums[i]);
            m[nums[i - k]]--;
            if (m[nums[i - k]] == 0) m.erase(nums[i - k]);
            m[nums[i]]++;
            if (m.size() == k) {
                ans = max(ans, pref[i] - pref[i - k]);
                // cout<<i<<" "<<i-k<<" ";
                // cout<<pref[i]<<" "<<pref[i-k]<<" ";
                // cout<<ans<<endl;
            }
        }
        return ans;
    }
};