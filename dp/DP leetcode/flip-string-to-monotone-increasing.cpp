class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count1 = 0;
        int flip = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                count1++;
            }
            if (s[i] == '0') {
                if (count1) {
                    flip++;
                }
            }
            if (count1 < flip) {
                flip = count1;
            }
        }

        return flip;
    }
};