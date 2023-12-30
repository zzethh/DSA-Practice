class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        // for(auto x:nums) cout<<x<<" ";
        // cout<<endl;
        vector<vector<int>> v;
        vector<int> temp;
        temp.push_back(nums[0]);
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int cnt = 1;
            ///cout<<prev<<"->";
            while (i < nums.size() and nums[i] <= prev + k) {
                // cout<<nums[i]<<" ";
                if (cnt >= 3) {
                    break;
                }
                temp.push_back(nums[i]);
                i++;
                cnt++;
            }
            if (cnt < 3) return {};
            else v.push_back(temp);
            temp.clear();
            temp.push_back(nums[i]);
            prev = nums[i];
            //cout<<endl;
        }
        return v;
    }
};