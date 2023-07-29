class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // int cnt=0;
        // map<int,int> m;
        // int j=0;
        // for(int i=0;i<nums.size();i++){
        //     m[nums[i]]++;
        //     auto it=m.begin();
        //     auto rit=m.rbegin();
        //     if(it->first>minK and rit->first<maxK){
        //         continue;
        //     }
        //     else if(it->first==minK and rit->first==minK){
        //         cnt++;
        //     }
        //     else{
        //         m.clear();
        //         i++;
        //     }
        // }
        // return cnt;
        long long ans = 0;
        int badi = -1, mini = -1, maxi = -1, n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i]<minK or nums[i]>maxK) badi = i;
            if (nums[i] == minK) mini = i;
            if (nums[i] == maxK) maxi = i;
            ans += max(0, min(mini, maxi) - badi);
        }
        return ans;
    }
};