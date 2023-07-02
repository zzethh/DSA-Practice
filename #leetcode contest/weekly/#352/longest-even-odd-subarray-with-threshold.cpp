class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        int n = nums.size();
        //nums.resize(nums.size()+1,nums[nums.size()-1]+1);
        // for(auto x:nums){
        //     cout<<x<<" ";
        // }
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                bool flag = false;
                for (int j = i; j < n; j++) {
                    for (int k = i; k < j; k++) {
                        if (nums[k] > threshold or nums[k] % 2 == nums[k + 1] % 2) {
                            flag = true;
                            break;
                        }
                        //cout<<"i: "<<i<<"j: "<<j<<endl;
                        //ans=max(ans,j-i+1);
                    }
                    if (nums[j] > threshold) break;
                    if (flag) break;
                    else {
                        //cout<<"i: "<<i<<"j: "<<j<<endl;
                        ans = max(ans, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
};