class Solution {
public:
    int helper(int n) {
        int sum = 0;
        while (n) {
            int rem = n % 10;
            sum = sum + (rem * rem);
            n = n / 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        int slow = n;
        int fast = n;

        do {
            slow = helper(slow);
            fast = helper(helper(fast));

        } while (slow != fast);

        return slow == 1;
    }
};