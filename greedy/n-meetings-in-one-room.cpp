class Solution
{
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static cmp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({start[i], end[i]});
        }

        sort(v.begin(), v.end(), cmp);

        int lowest = 0;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (v[lowest].second < v[i].first) {
                cnt++;
                lowest = i;
            }
        }

        return cnt;
    }
};