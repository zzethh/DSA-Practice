class Solution {
public:
    int countDigits(int num) {
        vector<int> dig;
        int temp = num;
        while (num) {
            int rem = num % 10;
            num = num / 10;
            dig.push_back(rem);
        }
        int cnt = 0;
        for (auto x : dig) {
            if (temp % x == 0) cnt++;
        }
        return cnt;
    }
};