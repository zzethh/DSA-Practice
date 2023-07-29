class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for (int i = 0; i <= num; i++) {
            int a = i;
            string n = to_string(i);
            reverse(n.begin(), n.end());

            if (a + stoi(n) == num) return true;
        }
        return false;
    }
};