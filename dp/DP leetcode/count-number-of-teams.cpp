class Solution {
public:
    int cnt = 0;
    void helper(vector<int> &rating, int i, int prev, int j) {
        if (j == 3) {
            cnt++;
            return;
        }
        if (i == rating.size()) {
            return;
        }
        if (prev == -1 or rating[i] > rating[prev]) {
            helper(rating, i + 1, i, j + 1);
        }
        helper(rating, i + 1, prev, j);
    }

    void helper2(vector<int> &rating, int i, int prev, int j) {
        if (j == 3) {
            cnt++;
            return;
        }
        if (i == rating.size()) {
            return;
        }

        if (prev == -1 or rating[i] < rating[prev]) {
            helper2(rating, i + 1, i, j + 1);
        }
        helper2(rating, i + 1, prev, j);
    }

    int numTeams(vector<int>& rating) {
        helper(rating, 0, -1, 0);
        helper2(rating, 0, -1, 0);
        return cnt;
    }
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        for (int i = 0; i < rating.size() - 1; i++) {
            int lsmall = 0;
            int llarge = 0;
            int rsmall = 0;
            int rlarge = 0;
            for (int j = 0; j < i; j++) {
                if (rating[j] > rating[i]) {
                    llarge++;
                }
                if (rating[j] < rating[i]) {
                    lsmall++;
                }
            }
            for (int j = i + 1; j < rating.size(); j++) {
                if (rating[j] > rating[i]) {
                    rlarge++;
                }
                if (rating[j] < rating[i]) {
                    rsmall++;
                }
            }
            ans += (llarge * rsmall) + (lsmall * rlarge);
        }
        return ans;
    }
};