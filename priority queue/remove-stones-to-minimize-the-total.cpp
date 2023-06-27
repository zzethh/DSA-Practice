class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (auto x : piles) {
            pq.push(x);
        }
        while (k--) {
            int top = pq.top();
            pq.pop();
            //cout<<top<<"->";
            double temp = (1.0 * top) / 2;
            // cout<<temp<<endl;
            pq.push(ceil(temp));
        }
        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            // cout<<pq.top()<<endl;
            pq.pop();
        }
        return sum;
    }
};