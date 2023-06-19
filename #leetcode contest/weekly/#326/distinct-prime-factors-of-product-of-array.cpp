class Solution {
public:
    void primefac(int num, unordered_set<int> &s) {
        for (int i = 2; i * i <= num; i++) {
            while (num % i == 0) {
                num = num / i;
                s.insert(i);
            }
        }
        if (num > 1) {
            s.insert(num);
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        int prod = 1;
        unordered_set<int> s;
        for (auto x : nums) {
            primefac(x, s);
        }
        return s.size();
    }
};