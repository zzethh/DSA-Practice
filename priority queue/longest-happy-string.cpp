class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0)pq.push({a, 'a'});
        if (b > 0)pq.push({b, 'b'});
        if (c > 0)pq.push({c, 'c'});
        string s = "";
        while (true) {
            if (!pq.empty()) {
                auto top = pq.top();
                pq.pop();
                if (s.length() >= 2 and s[s.length() - 1] == top.second and s[s.length() - 2] == top.second) {
                    pair<int, char> second;
                    if (!pq.empty()) second = pq.top();
                    else break;
                    s += second.second;
                    pq.pop();
                    pq.push(top);
                    if (second.first - 1 >= 1) pq.push({second.first - 1, second.second});
                }
                else {
                    s += top.second;
                    if (top.first - 1 >= 1) pq.push({top.first - 1, top.second});
                }
            }
            else break;
        }
        return s;
    }
};