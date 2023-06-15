class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = 0;
        int score2 = 0;
        int n = player1.size();
        for (int i = 0; i < min(2, n); i++) {
            if (i == 1) {
                if (player1[i - 1] == 10) score1 += 2 * player1[i];
                else score1 += player1[i];
            }
            else score1 += player1[i];
        }
        for (int i = 2; i < player1.size(); i++) {
            if (player1[i - 1] == 10 or player1[i - 2] == 10) score1 += 2 * player1[i];
            else score1 += player1[i];
        }

        for (int i = 0; i < min(2, n); i++) {
            if (i == 1) {
                if (player2[i - 1] == 10) score2 += 2 * player2[i];
                else score2 += player2[i];
            }
            else score2 += player2[i];
        }
        for (int i = 2; i < player2.size(); i++) {
            if (player2[i - 1] == 10 or player2[i - 2] == 10) score2 += 2 * player2[i];
            else score2 += player2[i];
        }

        if (score1 == score2) return 0;
        else if (score2 > score1) return 2;
        return 1;
    }
};