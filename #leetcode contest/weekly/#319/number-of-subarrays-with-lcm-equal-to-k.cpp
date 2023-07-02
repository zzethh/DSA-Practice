class Solution {
public:
    long long gcd(long long a, long long b) {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a * b) / gcd(a, b);
    }
    int subarrayLCM(vector<int>& nums, int k) {
        long long cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long prod2 = 1;
            for (int j = i; j < nums.size(); j++) {
                // if(lcm(prod2,nums[j])==k){
                //     //cout<<"i: "<<i<<" j: "<<j<<endl;
                //     cnt++;
                //     prod2=lcm(prod2,nums[j]);
                //     if(prod2>k) break;
                //    // continue;
                // }
                prod2 = lcm(prod2, nums[j]);
                if (prod2 > k) break;
                if (prod2 == k) cnt++;
                //else if(lcm(prod2,nums[j])>k) break;
                //prod2=prod2*nums[j];
            }
        }
        //cout<<lcm(18,2);
        return cnt;
    }
};