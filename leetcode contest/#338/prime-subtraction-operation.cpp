class Solution {
public:
    int isprime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int findprime(int n) {
        for (int i = n - 1; i >= 2; i--) {
            if (isprime(i)) {
                return i;
            }
        }
        return 0;
    }

    bool primeSubOperation(vector<int>& nums) {
        int x = findprime(nums[0]);
        cout << x << endl;
        if (nums[0] - x >= 0) {
            nums[0] = nums[0] - x;
        }

        for (int i = 1; i < nums.size(); i++) {
            int f = findprime(nums[i]);
            if (nums[i] <= nums[i - 1]) return false;
            while (nums[i] - f >= 0) {
                nums[i] = nums[i] - f;
                if (nums[i] <= nums[i - 1]) {
                    nums[i] = nums[i] + f;
                    f = findprime(f);
                }
                else break;
            }
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) return false;
        }
        return true;
    }
};