class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        // deque<int> d;
        // for(auto x:d){
        //     d.push_back(x);
        // }
        // long long ans=0;
        // while(d.size()!=1 or !d.empty()){
        //     auto a=d.front();
        //     auto b=d.back();
        //     d.pop_front();
        //     d.pop_back();
        //     ans=ans+a+b;
        // }
        // if(!d.empty()) ans+=d.front();
        int i = 0;
        int j = nums.size() - 1;
        long long ans = 0;
        while (i < j) {
            //string a="";
            // if(i==j) a=to_string(nums[i]);
            // else a=to_string(nums[i])+to_string(nums[j]);
            // int dig=a-'0';
            int maxi = nums[i];
            int mini = nums[j];
            int temp = mini;
            int cnt = 0;
            while (mini) {
                mini = mini / 10;
                cnt++;
            }
            maxi = maxi * pow(10, cnt) + mini;
            ans += temp + maxi;
            i++;
            j--;
        }
        if (i == j) ans += nums[i];
        return ans;
    }
};