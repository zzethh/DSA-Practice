class Solution {
public:
    int maxi = INT_MIN;
    void helper(vector<vector<int>>& students, vector<vector<int>>& mentors, vector<bool> m, int score, int k) {
        if (k == students.size()) {
            maxi = max(maxi, score);
            return;
        }
        for (int i = 0; i < mentors.size(); i++) {
            if (m[i]) continue;
            else {
                int temp = 0;
                for (int j = 0; j < mentors[i].size(); j++) {
                    if (students[k][j] == mentors[i][j]) {
                        temp++;
                    }
                }
                m[i] = 1;
                helper(students, mentors, m, score + temp, k + 1);
                m[i] = 0;
            }
        }
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<bool> m(mentors.size(), false);
        helper(students, mentors, m, 0, 0);
        return maxi;
    }
};