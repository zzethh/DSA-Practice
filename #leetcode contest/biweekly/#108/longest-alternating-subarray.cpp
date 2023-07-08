class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int cnt = 0;
        int maxi = -1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                cnt++;
                bool flag = true;
                bool flag2 = true;
                for (int k = i + 1; k <= j; k++) {
                    if (flag) {
                        if (nums[k] - nums[k - 1] != 1) {
                            cnt--;
                            flag2 = false;
                            break;
                        }
                    }
                    else {
                        if (nums[k] - nums[k - 1] != -1) {
                            cnt--;
                            flag2 = false;
                            break;
                        }
                    }
                    flag = !flag;
                }
                if (flag2) {
                    maxi = max(maxi, j - i + 1);;
                    // for(int m=i;m<=j;m++){
                    //     cout<<nums[m]<<" ";
                    // }
                    // cout<<endl;
                }
                else break;
            }
        }
        //cout<<cnt<<endl;
        return maxi;
    }
};