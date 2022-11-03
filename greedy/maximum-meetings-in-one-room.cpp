class Solution {
public:
        bool static cmp(vector<int> a, vector<int> b) {
                if (a[1] == b[1]) return a[2] < b[2];
                return a[1] < b[1];
        }

        vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
                vector<vector<int>> v;
                for (int i = 0; i < N; i++) {
                        v.push_back({S[i], F[i], i + 1});
                }

                sort(v.begin(), v.end(), cmp);

                int lowest = 0;
                vector<int> ans;
                ans.push_back(v[0][2]);
                for (int i = 1; i < N; i++) {
                        if (v[lowest][1] < v[i][0]) {
                                ans.push_back(v[i][2]);
                                lowest = i;
                        }
                }
                sort(ans.begin(), ans.end());
                return ans;
        }
};