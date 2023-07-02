class Solution {
public:
    int diff(multiset<int> &s) {
        auto it = s.begin();
        auto it2 = s.end();
        it2--;
        return (*it2) - (*it);
    }
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> s;
        int j = 0;
        long long cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
            while (diff(s) > 2) {
                s.erase(s.find(nums[j]));
                j++;
            }
            cnt += i - j + 1;
        }
        return cnt;
    }
};