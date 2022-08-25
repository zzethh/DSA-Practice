class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq(amount.begin(), amount.end());
        int cnt = 0;
        while (!pq.empty()) {
            if (pq.top() == 0) {
                return cnt;
            }
            cnt++;
            int max1 = pq.top();
            int max2 = 1;
            pq.pop();
            if (pq.size() >= 1) {
                max2 = pq.top();
                pq.pop();
            }
            max1 = max1 - 1;
            max2 = max2 - 1;
            if (max1 > 0) {
                pq.push(max1);
            }
            if (max2 > 0) {
                pq.push(max2);
            }
        }
        return cnt;
    }
};