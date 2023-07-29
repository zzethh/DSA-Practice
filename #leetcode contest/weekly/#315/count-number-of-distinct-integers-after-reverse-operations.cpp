class Solution {
public:
    int reverse(int num)
    {
        int rev_num = 0;
        while (num > 0) {
            rev_num = rev_num * 10 + num % 10;
            num = num / 10;
        }
        return rev_num;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for (auto x : nums) {
            s.insert(x);
            s.insert(reverse(x));
        }
        return s.size();
    }
};