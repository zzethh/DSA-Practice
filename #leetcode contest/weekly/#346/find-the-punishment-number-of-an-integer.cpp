class Solution {
public:
    bool helper(string num, int resSum, int dig) {
        if ((resSum<dig or resSum>dig) and num.empty()) {
            return false;
        }
        if (resSum == dig and num.empty()) {
            return true;
        }
        for (int i = 0; i < num.length(); i++) {
            string s = num.substr(0, i + 1);
            bool subprob = helper(num.substr(i + 1), resSum + stoi(s), dig);
            if (subprob) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            string dig = to_string(i);
            string num = to_string(i * i);
            if (helper(num, 0, i)) {
                sum += i * i;
            }
        }
        return sum;
    }
};