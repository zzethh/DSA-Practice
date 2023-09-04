class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) {
        int cnttrue = 0;
        int cntfalse = 0;
        int maxf = 0;
        int maxt = 0;
        int j = 0;
        int cnt = 0;
        int last_tr = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == 'F') {
                cntfalse++;
            }
            while (cntfalse > k) {
                if (ans[j] == 'F') cntfalse--;
                j++;
            }
            maxt = max(i - j + 1, maxt);
        }

        j = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == 'T') {
                cnttrue++;
            }
            while (cnttrue > k) {
                if (ans[j] == 'T') cnttrue--;
                j++;
            }
            maxf = max(i - j + 1, maxf);
        }
        return max(maxf, maxt);
    }
};