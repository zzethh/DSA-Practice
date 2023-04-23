class Solution {
public:
    int getmin(map<int, int> &m, int x) {
        int smallest = 0;
        for (auto f : m) {
            if (f.first < 0) {
                smallest += f.second;
            }
            else {
                return 0;
            }
            if (smallest >= x) {
                return f.first;
            }
        }
        return 0;
    }

    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            m[nums[i]]++;
        }
        ans.push_back(getmin(m, x));
        for (int i = k; i < nums.size(); i++) {
            ///contract
            m[nums[i - k]]--;
            if (m[nums[i - k]] == 0) m.erase(nums[i - k]);

            //expand
            m[nums[i]]++;

            ans.push_back(getmin(m, x));
        }
        return ans;
    }
};