class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int sum = 0;
        sort(costs.begin(), costs.end());
        int i = 0;
        int cnt = 0;
        while (i < costs.size() and sum + costs[i] <= coins) {
            sum += costs[i];
            i++;
            cnt++;
        }
        return cnt;
    }
};