class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int h1 = 0, m1 = 0;
        int h2 = 0, m2 = 0;
        int h3 = 0, m3 = 0;
        int h4 = 0, m4 = 0;
        bool flag = 0;
        for (int i = 0; i < event1[0].length(); i++) {
            if (event1[0][i] == ':') {
                flag = true;
                continue;
            }
            if (flag) {
                m1 = (m1 * 10) + event1[0][i] - '0';
                continue;
            }
            char c = event1[0][i];
            int dig = c - '0';
            h1 = (h1 * 10) + dig;
        }
        flag = 0;
        for (int i = 0; i < event1[1].length(); i++) {
            if (event1[1][i] == ':') {
                flag = true;
                continue;
            }
            if (flag) {
                m2 = (m2 * 10) + event1[1][i] - '0';
                continue;
            }
            int dig = event1[1][i] - '0';
            h2 = (h2 * 10) + dig;
        }
        flag = 0;
        for (int i = 0; i < event2[0].length(); i++) {
            if (event2[0][i] == ':') {
                flag = true;
                continue;
            }
            if (flag) {
                m3 = (m3 * 10) + event2[0][i] - '0';
                continue;
            }
            int dig = event2[0][i] - '0';
            h3 = (h3 * 10) + dig;
        }
        flag = 0;
        for (int i = 0; i < event2[1].length(); i++) {
            if (event2[1][i] == ':') {
                flag = true;
                continue;
            }
            if (flag) {
                m4 = (m4 * 10) + event2[1][i] - '0';
                continue;
            }
            int dig = event2[1][i] - '0';
            h4 = (h4 * 10) + dig;
        }
        //vector<pair<int,int>> v={{h1,m1},{h2,m2},{h3,m3},{h4,m4}};

        int a = h1 * 60 + m1;
        int b = h2 * 60 + m2;
        int c = h3 * 60 + m3;
        int d = h4 * 60 + m4;
        if (a >= c and a <= d) return true;
        if (c >= a and c <= b) return true;
        return false;
    }
};