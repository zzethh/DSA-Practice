class Solution {
public:

    int addMinimum(string word) {
        string s = "";
        int cnt = 0;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == 'a') {
                if (word[i + 1] == 'b') {
                    if (word[i + 2] == 'c') {
                        i = i + 2;
                    }
                    else {
                        cnt += 1;
                        i++;
                    }
                }
                else if (word[i + 1] == 'c') {
                    cnt += 1;
                    i = i + 1;
                }
                else {
                    cnt += 2;
                }
            }
            else if (word[i] == 'b') {
                if (word[i + 1] == 'c') {
                    cnt += 1;
                    i = i + 1;
                }
                else {
                    cnt += 2;
                }
            }
            else if (word[i] == 'c') {
                cnt += 2;
            }
        }
        return cnt;

    }
};