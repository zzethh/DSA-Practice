class Solution {
public:
        bool static cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
                if (a.first.second == b.first.second) return a.second < b.second;
                return a.first.second < b.first.second;
        }

        vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
                vector<pair<pair<int, int>, int>> v;
                for (int i = 0; i < N; i++) {
                        v.push_back({{S[i], F[i]}, i + 1});
                }

                sort(v.begin(), v.end(), cmp);

                int lowest = 0;
                vector<int> ans;
                ans.push_back(v[0].second);
                for (int i = 1; i < N; i++) {
                        if (v[lowest].first.second < v[i].first.first) {
                                ans.push_back(v[i].second);
                                lowest = i;
                        }
                }
                sort(ans.begin(), ans.end());
                return ans;
        }
};