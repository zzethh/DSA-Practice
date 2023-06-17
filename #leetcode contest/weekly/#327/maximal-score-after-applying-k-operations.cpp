class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        map<long, long> m;
        for (auto x : nums) {
            m[x]++;
        }
        long long score = 0;
        while (k--) {
            auto x = m.rbegin();
            score += x->first;
            m[x->first]--;
            long double a = x->first;
            long double b = 3;
            long double n = a / b;
            long long y = ceil(n);
            //cout<<ceil(10/3);
            // cout<<x->first<<" ";
            // cout<<y<<endl;
            m[y]++;
            if (m[x->first] <= 0) {
                m.erase(x->first);
            }
            //cout<<x->first<<" ";
        }
        return score;
    }
};