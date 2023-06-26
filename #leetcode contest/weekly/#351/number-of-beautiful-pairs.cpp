class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    int countBeautifulPairs(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int first = 0;
            while (n) {
                first = n % 10;
                n = n / 10;
            }
            cout << first << " ";
            for (int j = i + 1; j < nums.size(); j++) {
                int last = nums[j] % 10;
                cout << last << endl;
                if (gcd(first, last) == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};