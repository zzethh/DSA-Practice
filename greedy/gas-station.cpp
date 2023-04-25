class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < gas.size(); i++) {
            sum1 += gas[i];
            sum2 += cost[i];
        }
        if (sum1 < sum2) return -1;
        int curr = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curr += (gas[i] - cost[i]);
            if (curr < 0) {
                start = i + 1;
                curr = 0;
            }
        }

        return start;
    }
};