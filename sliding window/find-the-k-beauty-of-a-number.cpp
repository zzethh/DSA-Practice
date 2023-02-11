class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int cnt = 0;
        int n = s.length();
        for (int i = 0; i <= n - k; i++) {
            int nums = 0;
            for (int j = i; j < i + k; j++) {
                int dig = s[j] - '0';
                nums = nums * 10;
                nums = nums + dig;
            }
            if (nums == 0) continue;
            if (num % nums == 0) cnt++;
        }
        return cnt;
    }
};