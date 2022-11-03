class Solution
{
public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr + n);
        long long cost = 0;
        while (pq.size() > 1) {
            long long a = pq.top();
            pq.pop();

            long long b = pq.top();
            pq.pop();

            long long rope = a + b;

            cost = cost + rope;
            pq.push(rope);
        }

        return cost;
    }
};