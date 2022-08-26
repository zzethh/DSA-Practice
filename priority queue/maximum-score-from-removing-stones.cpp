class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int arr[] = {a, b, c};
        priority_queue<int> pq(arr, arr + 3);
        int cnt = 0;
        while (pq.size() > 1) {
            if (pq.top() == 0) {
                break;
            }
            cnt++;
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if (first - 1 > 0 && pq.empty() != 1) {
                pq.push(first - 1);
            }
            if (second - 1 > 0 && pq.empty() != 1) {
                pq.push(second - 1);
            }
        }
        return cnt;
    }
};