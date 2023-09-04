class Solution {
public:
    map<pair<int, int>, int> mp;
    bool helper(vector<int>& nums, int m, int sum, int start, int end) {
        if (end - start + 1 == 2) return true;
        if (start >= end) return true;
        if (mp.find({start, end}) != mp.end()) return mp[ {start, end}];
        int x = 0;
        for (int i = start; i <= end; i++) {
            x += nums[i];
            if (i == start) {
                if (sum - nums[start] >= m) {
                    if (helper(nums, m, sum - nums[start], start + 1, end)) {
                        return mp[ {start, end}] = true;
                    }
                }
            }
            else if (i == end) {
                if (sum - nums[end] >= m) {
                    if (helper(nums, m, sum - nums[end], start, end - 1)) {
                        return mp[ {start, end}] = true;
                    }
                }
            }
            else if (x >= m and sum - x >= m) {
                bool one = helper(nums, m, x, start, i);
                bool two = helper(nums, m, sum - x, i + 1, end);
                if (one and two) {
                    return mp[ {start, end}] = true;
                }
            }
        }
        // bool three=false;
        // bool four=false;
        // if(sum-nums[start]>=m) three=helper(nums,m,sum-nums[start],start+1,end);
        // if(sum-nums[end]>=m) four=helper(nums,m,sum-nums[end],start,end-1);
        // if(three or four) return true;
        return mp[ {start, end}] = false;
    }
    bool canSplitArray(vector<int>& nums, int m) {
        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        //cout<<sum<<endl;
        //vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size(),-1));
        return helper(nums, m, sum, 0, nums.size() - 1);
    }
};